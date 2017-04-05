#include "headers.h"

char *splitstr(char *str, const char *delim, char **saveptr)
{
	char *tok;
	int i;

	if (str == NULL)
	{
		if (*saveptr == NULL)
			return (NULL);
		str = *saveptr;
	}
	i = 0;
	tok = str;
	while (*str != '\0' && *str != EOF && *str != *delim)
	{
		str++;
		i++;
	}
	if (*str == '\0')
		*saveptr = NULL;
	else
		if (saveptr != NULL)
			*saveptr = str + 1;
	tok[i] = '\0';
	return (tok);
}

/**
 * build_env - creates a linked list of environmental variabls
 *
 * @head: pointer to the first node in linked list
 * @env: environmental variables
 *
 * Return: void
 */

env_t *build_env_list(env_t **head, char **environ)
{
	env_t *new_node;
	env_t *temp_node;
	char *token;
	char *saveptr;
	char equals = '=';
	char newline = '\n';

	environ++;
	while (*(environ + 1))
	{
		new_node = malloc(sizeof(env_t) * 8 - 1);
		if (!new_node)
			return (NULL);
//		token = strtok(*environ, "=");
		token = splitstr(*environ, &equals, &saveptr);
		if (token)
			new_node->key = _strdup(token);
//		token = strtok(NULL, "=");
		token = splitstr(NULL, &newline, &saveptr);
		if (token)
			new_node->value = _strdup(token);
		if (!*head)
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
		environ++;
	}
	return (*head);
}
