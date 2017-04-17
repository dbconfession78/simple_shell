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
	env_t *env_head = NULL;
	char *line = NULL;
	size_t line_size = 0;
	char **args = NULL;
	info_t *info = malloc(sizeof(info_t));

	if (info == NULL)
		return (-1);
	init_shell(info);
	info->env_head = init_env_list(environ, &env_head);

/* START TEST */
/* END TEST */
	path = _getenv("PATH", env_head)->value;
	path_head = list_tokenized_path(path);
	info->path_head = path_head;
	signal(SIGINT, signal_handler);
	if (argc == 1)
		set_prompt();
	while (getline(&line, &line_size, stdin) != EOF)
	{
		info->line = line;
		if (_strcmp(line, "\n") == 0)
		{
			set_prompt();
			continue;
		}
		args = tokenize_stdin(line);
		if (!(exec_builtin_cmd(args[0], args, info)))
			if(!exec_path_cmd(args[0], args, path_head))
				perror("Error");
		free(args);
		set_prompt();
	}
	free_env_list(env_head);
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
 * init_shell - initializes variables held by the info_t struct
 * @info: info_t struct whose variables are to be initialized
 * Return: void
 */

void init_shell(info_t *info)
{
	info->env_head = NULL;
	info->path_head = NULL;
	info->line = NULL;
}
