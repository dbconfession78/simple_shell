#include "shell.h"

int main(int ac, char **av)
{
	char *path, *cmd = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;

	write(1, "$ ", 2);
	while ((read = getline(&cmd, &len, stdin)) != EOF)
	{
		args = _parse(cmd);
		if (execve(av[0], av, env) == -1)
			perror("Error ");
		write(1, "$ ", 2);
		free(args);
	}
	free (cmd);
	return (0);
}
char **_parse(char *cmd)
{
	char *token, *delim = " ";
	char **args = NULL;
	size_t i = 0;

	args = malloc(sizeof(args) *  _strlen(cmd));
	token = strtok(cmd, delim);
	while(token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		++i;
	}
	return(args);
}
