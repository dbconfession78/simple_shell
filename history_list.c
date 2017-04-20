#include "shell.h"

/**
 * add_history - adds a node to the hist_t list
 * @count: pointer to hist_count
 * @head: pointer to first node in hist_t list
 * @cmd: command line added to history
 * Return: the added history node
 */
hist_t *add_history(int *count, hist_t **head, char *cmd)
{
	hist_t *new_node;
	hist_t *temp_node;


	if (!cmd || cmd[0] == ' ')
		return (NULL);

	new_node = malloc(sizeof(hist_t));

	if (!new_node)
		return (NULL);

	new_node->cmd = _strdup(cmd);
	if (!*head)
	{
		new_node->index = 0;
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		*count = *count + 1;
		new_node->next = NULL;
		temp_node = *head;
		while (temp_node->next)
			temp_node = temp_node->next;

		new_node->index = *count;
		temp_node->next = new_node;
	}
	return (new_node);
}
