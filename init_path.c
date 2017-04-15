#include "shell.h"
/**
*
*
*/
int init_path(void)
{
	path_t *path = NULL;
	char *list = _getenv("PATH");

	if (!list)
		return (-1);
	path = path_list(list, path);
/*	print_path(path);*/
	free_path(path);
	return (0);
}
/**
*
*/
path_t *add_pathnode_end(path_t **head, const char *str)
{
	path_t *new_node = malloc(sizeof(path_t));
	path_t *temp_node;
	char *data = malloc(sizeof(char) * (_strlen(str) + 2));

	_strcpy(data, str);
	_strcat(data, "/");
	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->dir = _strdup(data);
	new_node->next = NULL;
	free(data);
	printf("str: %s\n", new_node->dir);
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

path_t *path_list(char *list, path_t *head)
{
	char *token;
	
	if (!list)
		return (NULL);
	token = strtok(list, ":");
	while (token)
	{
		add_pathnode_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}/*
void print_path(const path_t *h)
{
	while (h)
	{
		puts(h->dir);
		h = h->next;
	}
}*/
char *_getenv(const char *name)
{
	extern char **environ;
	const char *token;
	char *match;

	if (!name)
		return (NULL);
	while(*environ)
	{
		token = strtok(*environ, "=");
		if (strcmp(name, token) == 0)
		{
			match = strtok(NULL, "\0");
			return (match);
		}
		environ++;
	}
	return (NULL);
}
void free_path(path_t *head)
{
	path_t *i = head;
	path_t *next = NULL;

	for (; i != NULL; i = next)
	{
		next = i->next;
		free(i->dir);
		free(i);
	}
}
