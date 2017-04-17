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
