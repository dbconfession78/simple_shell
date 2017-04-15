#include "shell.h"

/**
 * signal_handler - writes a newline and sets prompt when passed
 *                  to signal( )
 * @sig: number corresponding to a signal
 * Return: void
 */

void signal_handler(int sig)
{
	(void) sig;
	write(0, "\n", 1);
	set_prompt();
}

/**
 * set_prompt - sets standard '$ ' prompt
 * Return: void
 */

void set_prompt(void)
{
	write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
}

/**
 * tokenize_stdin - puts standard input line into an array
 * @line: line to tokenize
 * Return: array of tokens
 */
char **tokenize_stdin(char *line)
{
	char **result;
	size_t i = 0;
	int word_count = 0;
	char *token;
	char *delim = "\n\r\t\a ";
	char *line_copy;

	if (!line)
		return (NULL);
	line_copy = _strdup(line);
	token = strtok(line_copy, delim);
	while (token)
	{
		word_count++;
		token = strtok(NULL, delim);
	}
	token = strtok(line, delim);
	result = malloc(sizeof(char *) * (word_count + 1));
	while (token)
	{
		result[i++] = token;
		token = strtok(NULL, delim);
	}
	result[i] = NULL;
	free(line_copy);
	return (result);
}
