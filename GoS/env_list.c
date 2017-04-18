#include "shell.h"

/**
 * init_env_list - builds environmental variables linked list from extern
 * @environ: environmental varibales from extern
 * @head: pointer to start of list
 * Return: void
 */
env_t *init_env_list(char **environ, env_t **head)
{
	char *token, *env_var;
	env_t *new_node, *temp_node;
	int i = 0;

	while (environ[i])
	{
		new_node = malloc(sizeof(env_t));
		if (!new_node)
			return (NULL);
		env_var = _strdup(environ[i]);
		token = strtok(env_var, "=");
		if (token)
			new_node->name = _strdup(token);
		token = strtok(NULL, "\n");
		if (token)
			new_node->value = _strdup(token);
		free(env_var);
		if (*head == NULL)
		{
			new_node->next = *head;
			*head = new_node;
		}
		else
		{
			new_node->next = NULL;
			temp_node = *head;
			while (temp_node->next)
				temp_node = temp_node->next;

			temp_node->next = new_node;
		}
		i++;
	}

	return (*head);
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
	env_t *temp;

	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
		if (strcmp(name, temp->name) == 0)
		{
			temp->value = strdup(value);
			return (temp);
		}
	}
	add_env_node(head, name, value);
}

/**
 * add_env_node - adds new node at end of a list_t list.
 * @head: array of linked list_t structures
 * @name: env variable name
 * @value: env variable value
 * Return: address of added list element; NULL if failed.
 */
env_t *add_env_node(env_t **head, char *name, char *value)
{
	env_t *new_node = malloc(sizeof(env_t));
	env_t *temp_node;

	if (!new_node)
		return (NULL);

	new_node->name = _strdup(name);
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

/**
 * _getenv - get value of specified env variable
 * @var_name: name of env variable to get value of
 * @head: pointer to head of env_t iist
 * Return: value of requested env var
 */
env_t *_getenv(char *var_name, env_t *head)
{
	env_t *environ = head;

	while (environ)
	{
		if (_strcmp(var_name, environ->name) == 0)
			return (environ);
		environ = environ->next;
	}
	return (NULL);
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
