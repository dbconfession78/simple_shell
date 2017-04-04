#include "headers.h"

typedef struct path_s
{
	char *path;
	struct path_s *next;
} path_t;


size_t print_list(const path_t *h)
{
	size_t len = 0;

	while (h)
	{
		printf("%s\n", h->path);
		h = h->next;
		len++;
	}
	return (len);
}

int _strlen(const char *s)
{
	int c = 0;

	while (s[c])
		c++;
	return (c);
}

/**
 * add_node_end - adds new node at end of a list_t list.
 * @head: array of linked list_t structures
 * @str: string to add to this node
 * Return: address of added list element; NULL if failed.
 */

/* str needs to be duplicated */
/* can use strdup */
/* return NULL if failed */
path_t *add_node_end(path_t **head, const char *path)
{
	path_t *new_node = malloc(sizeof(path_t));
	path_t *temp_node;

	if (!new_node)
		return (NULL);

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
 * gets a specific environment variable
 */
char *_getenv(const char *name)
{
	extern char **environ;
	const char *token;
	char *result = malloc(sizeof(char) * 256);

	while(*environ)
	{
		token = strtok(*environ, "=");
		while(token)
		{
			if (strcmp(name, token) == 0)
			{
				token = strtok(NULL, "=");
				strcpy(result, token);
				return (result);
			}
			token = strtok(NULL, "=");
		}
		environ++;
	}
	return ("unable to locate requested environmental variable\n");
}

/**
 *
 */
int main (int argc, char **argv, char **env)
{
	path_t *head = NULL;
	//head = NULL;

	char *path, *token;
	path_t *p_list = malloc(sizeof(path_t) * 8 -1);
	path_t *temp;
	int i = 0;

	char **path_array = malloc(sizeof(char) * 8);
	path = _getenv("PATH");
	token = strtok(path, ":");

	while(token = strtok(NULL, ":"))
	{
		path_array[i] = token;
//		printf("%s\n", path_array[i]);
		i++;
	}

	add_node_end(&head, path_array[i]);
	//print_list(head);


	return (0);
}
