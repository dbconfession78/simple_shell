#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct env_s
{
	char *str;
	struct env_s *next;
} env_t;

size_t print_env_list(const env_t *head);
env_t *add_env_node(env_t **head, const char *str);
void init_env_list(char **environ, env_t **head);

#endif
