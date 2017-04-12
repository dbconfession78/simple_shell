#include "shell.h"

size_t print_list(const env_t *h)
{
	size_t len = 0;

	while (h)
	{
		printf("%s\n", h->str);
		h = h->next; len++;
	}
	return (len);
}

/**
 * main - entry point for shell programs
 * @argc: argument count
 * @argv: arguments supplied by user
 * @envp: pointer to environemental variables
 * Return - always return 0
 */

int main(int argc, char **argv, char **envp)
{
	(void) argc; (void) argv;
	char *line = NULL;
	char **tok_args;
	env_t *head = NULL;
	size_t len = 0;
	ssize_t read;

	init_env_list(envp, &head);
	write (STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	while ((read = getline(&line, &len, stdin)) != EOF)
	{
		tok_args = tokenize_string(line);
		handle_command(tok_args);
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		free(tok_args);
	}

	print_env_list(head);
	_setenv("lalala", "JARED", &head);
	_setenv("PATH", "no/more/path", &head);
	print_list(head);
}
