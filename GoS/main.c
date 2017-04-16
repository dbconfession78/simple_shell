#include "shell.h"

/**
 * main - entry point for shell
 * @argc: arg count
 * @argv: arguments
 * Return: always return 0
 */
int main(int argc, char *argv[])
{
	char *path = NULL;
	path_t *path_head = NULL;
	char *line = NULL;
	size_t line_size = 0;
	char **args = NULL;
	info_t *info = malloc(sizeof(info_t));

	if (info == NULL)
		return (-1);

	init_shell(info);
	path = _getenv("PATH");
	path_head = list_tokenized_path(path);
	info->path_head = path_head;
	signal(SIGINT, signal_handler);
	if (argc == 1)
		set_prompt();
	while (getline(&line, &line_size, stdin) != EOF)
	{
		info->line = line;
//		if (strcmp(line, "exit\n") == 0)
//			exit_shell(NULL, info);
		if (_strcmp(line, "\n") == 0)
		{
			set_prompt();
			continue;
		}
		args = tokenize_stdin(line);
		info->args = args;
		if(!(exec_builtin_cmd(args[0], args, info)))
		{
//			printf("didnt run built in. try running from path\n.\n");
			exec_path_cmd(args[0], args, path_head);
		}
		free(args);
		set_prompt();
	}
	free_path_list(path_head);
	free(line);
	free(info);
	return (EXIT_SUCCESS);
}

/**
 * list_tokenized_path - tokenizes and builds list from path directory string
 * @path: PATH directories
 * Return: pointer to head of newly formed path list
 */
path_t *list_tokenized_path(char *path)
{
	char *token;
	path_t *head = NULL;
	int i = 0;

	token = strtok(path, ":");
	while (token)
	{
		add_path_node_end(&head, token);
		token = strtok(NULL, ":");
		i++;
	}
	return (head);
}

/**
 * _getenv - get value of specified env variable
 * @var_name: name of env variable to get value of
 * Return: value of requested env var
 */
char *_getenv(char *var_name)
{
	char *env_value = NULL;

	if (!var_name)
		return (NULL);
	while (*environ)
	{
		env_value = strtok(*environ, "=");
		if (strcmp(var_name, env_value) == 0)
		{
			env_value = strtok(NULL, "\0");
			return (env_value);
		}
		environ++;
	}
	return (env_value);
}

void init_shell (info_t *info)
{
//	info->env = NULL;
	info->args = NULL;
	info->path_head = NULL;
	info->line = NULL;
}
