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
	env_t *head = NULL;
	init_env_list(envp, &head);
	print_env_list(head);
	_setenv("lalala", "JARED", &head);
	_setenv("PATH", "no/more/path", &head);
	print_env_list(head);
}
