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
	char **tokenized_stdin = NULL;

	path = _getenv("PATH");
	path_head = list_tokenized_path(path);
	signal(SIGINT, signal_handler);
	if (argc == 1)
		set_prompt();
	while (getline(&line, &line_size, stdin) != EOF)
	{
		if (_strcmp(line, "\n") == 0)
		{
			set_prompt();
			continue;
		}
		tokenized_stdin = tokenize_stdin(line);
		if(check_built_ins(tokenized_stdin[0], tokenized_stdin) == 1)
		{
			printf("*****TODO: CHECK  BUILT-INS*****\n");
			getchar();
			if (check_path(tokenized_stdin[0], tokenized_stdin, path_head) == 1)
			{
				perror("Error");
				
			}
		}
		else
		{
			printf("is a built-in\n");
			/* check_built_ins succeeded */
		}
		free(tokenized_stdin);
		set_prompt();
	}
	free_path_list(path_head);
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
