#include "shell.h"

/**
 * print_list - prints all the elements of a list_t list
 * @head: a linked list of type list_t
 * Return: number of list nodes
 */
size_t print_env_list(const env_t *head)
{
	size_t len = 0;

	while (head)
	{
		printf("%s\n", head->str);
		head = head->next; len++;
	}
	return (len);
}

/**
 * add_env_node - adds new node at end of a list_t list.
 * @head: array of linked list_t structures
 * @str: string to add to this node
 * Return: address of added list element; NULL if failed.
 */
env_t *add_env_node(env_t **head, const char *str)
{
	env_t *new_node = malloc(sizeof(env_t));
	env_t *temp_node;

	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
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


/**
 * init_env_list - builds environmental variables linked list from extern
 * @environ: environmental varibales from extern
 * @head: pointer to start of list
 * Return: void
 */
void init_env_list(char **environ, env_t **head)
{
	char *token;

	while (*environ)
	{
		token = strtok(*environ, "\n");
		while (token)
		{
			add_env_node(head, token);
			token = strtok(NULL, "\n");
		}
		environ++;
	}

}

env_t *_setenv(const char *name, const char *value, env_t **head)
{
	char *env_str = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	env_t *temp;

	if (!env_str)
		return (NULL);

	strcpy(env_str, name);
	strcat(env_str, "=");
	strcat(env_str, value);
	strcat(env_str, "\0");

	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
		if (strncmp(env_str, temp->str, _strlen(name)) == 0)
		{
			temp->str = strdup(env_str);
			free (env_str);
			return (temp);
		}
	}
	add_env_node(head, env_str);

//	tem("cat: %s\n", str);
}
int _unsetenv(char *name, env_t **head)
{
	env_t *temp = NULL;
	env_t *node = *head;
	size_t idx = 0;

	if (!*head || !head)
		return (-1);

	while (node != NULL)
	{
		temp = node;
		if (cmpname(name, temp->str) == 0)
		{
			if (idx == 0)
				*head = node->next;
			else
				temp->next = node->next;
			free(node);
			return (1);
		}
		node = node->next;
		idx++;
	}
	return (1);
}
int cmpname(char *name, const char *key)
{
	size_t i;

	if (key)
	{
		for (i = 0; key[i] != '='; i++)
		{
			if (name[i] != key[i])
				return (-1);
		}
		return (0);
	}
	return (-1);
}
