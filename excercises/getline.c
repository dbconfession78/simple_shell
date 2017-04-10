#include "shell.h"

int main(int ac, char **av)
{
	char *path, *cmd = NULL;
	char **args;
	size_t len = 0;
	ssize_t read;

	write(1, "$ ", 2);
	while ((read = getline(&cmd, &len, stdin)) != EOF)
	{
		write(1, cmd, read);
		args = _parse(cmd);
		printf("before free\n"); getchar();
		write(1, "$ ", 2);
		free(args);
	}
	printf("before cmd free\n");
	free (cmd);
	return (0);
}
char **_parse(char *cmd)
{
	char *token, *delim = " ";
	char **args;
	size_t i = 0;
	args = malloc(_strlen(cmd));

	printf("len: %d\n", _strlen(cmd));
	printf("test: %s\n", cmd);
	token = strtok(cmd, delim);
	while(token != NULL)
	{
		args[i] = token;
		printf("setting args value\n"); getchar();
		token = strtok(NULL, delim);
		++i;
	}
	return(args);
}
