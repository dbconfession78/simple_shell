#include "headers.h"

/**
 * add_node_end - adds new node at end of a list_t list.
 * @head: array of linked list_t structures
 * @str: string to add to this node
 * Return: address of added list element; NULL if failed.
 */

env_t *add_node_end(env_t **head, const char *key, const char*value)
{
	env_t *new_node = malloc(sizeof(env_t));
	env_t *temp_node;

	if (!new_node)
		return (NULL);

	new_node->key = _strdup(key);
	new_node->value = _strdup(value);
	new_node->next = NULL;

	if (!*head)
		*head = new_node;
	else
	{
		temp_node = *head;
		while (temp_node->next)
			temp_node = temp_node->next;

		temp_node->next = new_node;
	}
	return (new_node);
}
