#include "shell.h"

/**
 * change_directory - calls cd built-in
 * @dir: directory to change to
 * @args: arguments received at getline
 * Return: 0 on success, -1 on failure
 */
int change_directory(char *dir, char **args)
{
	pid_t pid;
	int status;

	if (!chdir(dir))
		return (-1);
	return (0);
}

/**
 * exit_shell - frees allocated memory and exits shell
 * @exit_status: number representing exit status
 * @args:  arguments received by getline
 * @info: shell information struct
 */
void exit_shell(char *exit_status, char **args, info_t *info)
{
	int i;

	if (exit_status != NULL)
		i = _atoi(exit_status);
	else
		i = 0;

	free(args);
	free(info->line);
	free_path_list(info->path_head);
	free_env_list(info->env_head);
	free(info);
	exit(i);
}

/**
 * print_env - prints the current environment
 *
 *
 * Return: void
 */

void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}
