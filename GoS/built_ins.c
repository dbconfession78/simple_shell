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

	if (chdir(dir) == -1)
	{
		printf("-1\n");
		return (-1);
	}
	printf("0\n");
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
 * @head: pointer to first node in env_t struct
 * Return: 0 on success;  -1 otherwise
 */
int print_env(env_t **head, info_t *info)
{
	char **env_array;
	int i = 0;
	env_t *temp_node = *head;

	while(temp_node->next)
	{
		temp_node = temp_node->next;
		printf("%s=%s\n", temp_node->name, temp_node->value);
	}
	return (0);
}
