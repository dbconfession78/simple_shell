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
	path_t *head = NULL;
	char *line = NULL;
	size_t line_size = 0;
	char **tokenized_stdin = NULL;

	path = _getenv("PATH");
	head = list_tokenized_path(path);
	free_path_list(head);
	signal(SIGINT, signal_handler);
	if (argc == 1)
		set_prompt();
	while (getline(&line, &line_size, stdin) != EOF)
	{
		tokenized_stdin = tokenize_stdin(line);
		free(tokenized_stdin);
		set_prompt();
	}
	if (line)
		free(line);
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
