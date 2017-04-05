#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct env_s
{
	char *key;
	char *value;
	struct env_s *next;
} env_t;

env_t *add_node_end(env_t **head, const char *key, const char *value);
char *_strdup(const char *str);
void _putchar(char c);
int _strlen(const char *str);
size_t print_list(const env_t *h);
env_t *build_env_list(env_t **head, char **environ);

#endif
