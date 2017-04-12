#include "shell.h"

/**
 * free_list - frees a list_t list
 * @head: array of linked list_t structures to free
 * Return: void
 */

void free_list(env_t *head)
{
	env_t *temp_node;

	if (!head)
		return;

	while (head)
	{
		temp_node = head->next;
		free(head->str);
		free(head);
		head = temp_node;
	}
}
