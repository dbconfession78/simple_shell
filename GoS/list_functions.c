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
 * add_path_node_end - adds new node at end of a list_t list.
 * @head: array of linked list_t structures
 * @path_dir: path directory
 * Return: address of added list element; NULL if failed.
 */

path_t *add_path_node_end(path_t **head, char *path_dir)
{
	path_t *new_node = malloc(sizeof(path_t));
	path_t *temp_node = NULL;
	char *data = malloc(sizeof(char) * _strlen(path_dir) + 2);

	if (!new_node || !data)
		return (NULL);

	_strcpy(data, path_dir);
	_strcat(data, "/");
	new_node->path_dir = _strdup(data);
	new_node->next = NULL;
	free(data);

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
