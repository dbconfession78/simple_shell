#include "shell.h"

char **tokenize_string(char *line)
{
	char *token, *delim = " \n";
	char **args = malloc(sizeof(char*) * 100);
	size_t i = 0;

	token = strtok(line, delim);
	while(token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		++i;
	}
	args[i] = NULL;
	return(args);
}
