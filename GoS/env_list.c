#include "shell.h"

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

/**
 * _setenv - edits value of existing variable or adds new var if doesn't exist
 * @name: name of env variable
 * @value: value of env variable
 * @head: pointer to first node in env_t list
 * Return: pointer to updated or new node
 */
env_t *_setenv(char *name, char *value, env_t **head)
{
	char *env_var = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	env_t *temp;

	if (!env_var)
		return (NULL);

	strcpy(env_var, name);
	strcat(env_var, "=");
	strcat(env_var, value);
	strcat(env_var, "\0");

	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
		if (strncmp(env_var, temp->env_var, _strlen(name)) == 0)
		{
			temp->env_var = strdup(env_var);
			free (env_var);
			return (temp);
		}
	}
	add_env_node(head, env_var);
}

/**
 * add_env_node - adds new node at end of a list_t list.
 * @head: array of linked list_t structures
 * @env_var: string to add to this node
 * Return: address of added list element; NULL if failed.
 */
env_t *add_env_node(env_t **head, const char *env_var)
{
	env_t *new_node = malloc(sizeof(env_t));
	env_t *temp_node;

	if (!new_node)
		return (NULL);

	new_node->env_var = strdup(env_var);
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
