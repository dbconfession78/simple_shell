#include "headers.h"

/**
 * main - shell entry point
 *
 *
 * Return: always returns 0
 */

int main (int argc, char *argv[], char **env)
{
	env_t *head = NULL;
	build_env_list(&head, env);
	print_list(head);

	return (0);
}
