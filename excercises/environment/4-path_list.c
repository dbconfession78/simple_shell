#include "headers.h"

int main(int ac, char **av)
{
	list_t *head = NULL;
	char *path = _getenv("PATH");

	if (!path)
		return (-1);
	head = path_list(path, head);
	print_list(head);
	free_path(head);
	return (0);
}

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

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *temp_node;
	char *data = malloc(sizeof(char) * (strlen(str) + 2));

	strcpy(data, str);
	strcat(data, "/");
	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = strdup(data);
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

void print_list(const list_t *h)
{
	while (h)
	{
		printf("%s\n", h->str);
		h = h->next;
	}
}/*
char *exepath(char *file, const list_t *h)
{
	struct stat st;
	char *tmp = malloc(sizeof(char) * strlen(file));

	if (!file || !h)
	{
		free(tmp);
		return (NULL);
	}
	tmp = file;
	while (h)
	{
		file = strcat(h->str, file);
		if (stat(file, &st) == 0)
		{
			printf("found %s\n", file);
			free(tmp);
			return (file);
		}
		else
			printf("not found %s\n", file);
		h = h->next;
		file = tmp;
	}
	free(tmp);
	return("fail");
}*/
list_t *path_list(char *path, list_t *head)
{
	char *token;
	
	if (!path)
		return (NULL);
	token = strtok(path, ":");
	while (token)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}
void free_path(list_t *head)
{
	list_t *i = head;
	list_t *next = NULL;

	for (; i != NULL; i = next)
	{
		next = i->next;
		free(i->str);
		free(i);
	}
}
