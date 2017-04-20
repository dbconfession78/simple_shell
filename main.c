#include "shell.h"

/**
 * main - entry point for shell
 * Return: always return 0
 */
int main(/*int argc, char *argv[]*/void)
{
	char *path = NULL, *line = NULL, **args = NULL;
	path_t *path_head = NULL;
	env_t *env_head = NULL;
	size_t line_size = 0;
	info_t *info = malloc(sizeof(info_t));
	int hist_count = 0, *hist_count_p = &hist_count;
	struct stat stats;

	if (info == NULL)
		return (-1);
	init_shell(info);
	info->env_head = init_env_list(environ, &env_head);
	path = _getenv("PATH", env_head)->value;
	path_head = list_tokenized_path(path);
	info->path_head = path_head;
	signal(SIGINT, signal_handler);
	fstat(0, &stats);
	if (S_ISCHR(stats.st_mode))
		set_prompt();
	while (getline(&line, &line_size, stdin) != EOF)
	{
		info->line = line;
		add_history(hist_count_p, &info->hist_head, line);
		if (_strcmp(line, "\n") == 0)
		{
			set_prompt();
			continue;
		}
		args = tokenize_stdin(line);
		run_command(args, info);
		free(args);
		set_prompt();
		if (!S_ISCHR(stats.st_mode))
			_putchar ('\n');
	}
	free_info_items(info);
	free(line);
	free(info);
	return (EXIT_SUCCESS);
}

/**
 * run_command - executes command with arguments
 * @args: arguments supplied at command line
 * @info: pointer to the info_t struct
 * Return: 0 if succesful; -1 otherwise
 */
int run_command(char **args, info_t *info)
{
	char *cmd = args[0];
	path_t *path_head = info->path_head;

	if (!(exec_builtin_cmd(cmd, args, info)))
	{
		printf("cmd: %s\n", cmd);
		if ((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/')
		{
			if (cmd[0] == '.')
				cmd = cmd + 2;
			if (!exec_filename(cmd, args))
			{
				perror("Error");
				return (-1);
			}
		}
		else
		{
			if (!exec_path_cmd(cmd, args, path_head, info))
			{
				perror("Error");
				return (-1);
			}
		}
	}
	return (0);
}

/**
 * list_tokenized_path - tokenizes and builds list from path directory string
 * @path: PATH directories
 * Return: pointer to head of newly formed path list
 */
path_t *list_tokenized_path(char *path)
{
	char *token;
	char *path_copy;
	path_t *head = NULL;
	int i = 0;

	path_copy = malloc(sizeof(char) * _strlen(path) + 1);
	if (!path_copy)
		return (NULL);

	_strcpy(path_copy, path);
	token = strtok(path_copy, ":");
	while (token)
	{
		add_path_node_end(&head, token);
		token = strtok(NULL, ":");
		i++;
	}
	free(path_copy);
	return (head);
}

/**
 * init_shell - initializes variables held by the info_t struct
 * @info: info_t struct whose variables are to be initialized
 * Return: void
 */
void init_shell(info_t *info)
{
	info->env_head = NULL;
	info->path_head = NULL;
	info->line = NULL;
	info->hist_head = NULL;
}
