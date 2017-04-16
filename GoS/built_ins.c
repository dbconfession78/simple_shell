#include "shell.h"

/**
 * change_directory - calls cd built-in
 *
 * @args: XXXXXXXXXXXXXXX
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
 * @stdin:  input used to call this function so it can be freed
 * @info: shell information struct
 */
void exit_shell(char *exit_status, info_t *info)
{
	int i;
	if (exit_status != NULL)
		i = _atoi(exit_status);
	else
		i = 0;


//	free(info->args[0]);

	free(info->args);
	free(info->line);
	free_path_list(info->path_head);
	free(info);
	//_exit(i & 255);
	exit(i);
}

/**
 * _printenv - prints the current environment
 *
 *
 * Return: void
 */

void print_env(void)
{
	int i = 0;
	while(environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}
