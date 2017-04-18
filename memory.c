#include "shell.h"

/**
 * free_path_list - frees a list_t list
 * @head: linked list
 * Return: void
 */
void free_path_list(path_t *head)
{
	path_t *i = head;
	path_t *next = NULL;

	for (; i != NULL; i = next)
	{
		next = i->next;
		free(i->path_dir);
		free(i);
	}
}

/**
 * free_env_list - frees a env_t list
 * @head: pointer to head of env_t list
 * Return: void
 */
void free_env_list(env_t *head)
{
	env_t *i = head;
	env_t *next = NULL;

	for (; i != NULL; i = next)
	{
		next = i->next;
		free(i->name);
		free(i->value);
		free(i);
	}
}

/**
 * free_string_array - frees memory allocated by a double pointer
 * @array: 2D array to free
 * Return: TRUE (1) on success; FALSE (0 on fail)
 */
int free_string_array(char **array)
{
	int i = 0;

	if (!array)
		return (FALSE);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (TRUE);
}

/**
 * free_info - frees all lements of the info_t struct
 * @info: pointer to the info_t struct
 * Return: void
 */
void free_info(info_t *info)
{
	free_env_list(info->env_head);
	free_path_list(info->path_head);
}
