#include "shell.h"

char **tokenize_string(char *line)
{
	char *token, *delim = " ";
	char **args;
	size_t i = 0;
	int spc = 0;

	token = strtok(line, delim);
	while(token != NULL)
	{
		spc++;
		token = strtok(NULL, delim);
	}
	args = malloc(_strlen(line) + spc);
	token = strtok(line, delim);
	while(token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		++i;
	}
	return(args);
}
