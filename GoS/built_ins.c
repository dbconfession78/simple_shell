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
int print_env(env_t **head)
{
	char **env_array;
	int i = 0;

	env_array = env_list_to_array(*head);
	if (!env_array)
		return (-1);
	while (env_array[i])
		printf("%s\n", env_array[i++]);
	free_string_array(env_array);
	return (0);
}

/**
 * env_list_to_array - puts env_t list values into a 2d array
 * @env_head: pointer to first node in env_t list
 * Return: pointer to array of env variables
 */
char **env_list_to_array(env_t *env_head)
{
	env_t *temp_node = env_head;
	char **result;
	int len = 0;
	int i = 0;

	while (temp_node->next)
	{
		temp_node = temp_node->next;
		len++;
	}
	temp_node = env_head;
	result = malloc(sizeof(char *) * (len + 1));
	while (temp_node->next)
	{
		result[i] = malloc(sizeof(char) * (_strlen(temp_node->name) +
										   _strlen(temp_node->value) + 2));
		_strcpy(result[i], temp_node->name);
		_strcat(result[i], "=");
		_strcat(result[i], temp_node->value);
		_strcat(result[i], "\0");
		temp_node = temp_node->next;
		i++;
	}
	result[i] = NULL;
	return (result);
}
