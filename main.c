#include "shell.h"

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
	info_t info;

	info = init_main(argc, argv, envp);
	init_env_list(envp, &head);
	signal(SIGINT, signal_handler);				
	set_prompt();
	while ((read = getline(&line, &len, stdin)) != EOF)
	{
		if (_strcmp(line, "\n") == 0)
		{
//write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
			set_prompt();
			continue;
		}
		tok_args = tokenize_string(line);
		handle_command(tok_args);
		set_prompt();
		free(tok_args);
	}

	//free(tok_args);
	free_list(head);
	free(line);

//	print_env_list(head);
//	_setenv("lalala", "JARED", &head);
//	_setenv("PATH", "no/more/path", &head);
//	print_env_list(head);

	return (0);
}

info_t init_main(int argc, char *argv[], char *envp[])
{
	int pid = getpid();
}
