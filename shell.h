#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#define PROMPT "$ "
typedef struct env_s
{
	char *str;
	struct env_s *next;
} env_t;

typedef struct info_s
{
	char **args;
	//*char bufnext
	//char *inphead;
	//char *buff_head
	env_t env_list;
//	int *buff_size;
//	int *printed;
//	int *last;
	char *pid;
//	int last_exit;
	int type;

	//long *total;
	//int file
} info_t;

size_t print_env_list(const env_t *head);
env_t *add_env_node(env_t **head, const char *str);
void init_env_list(char **environ, env_t **head);
int _unsetenv(char *name, env_t **head);
char **tokenize_string(char *line);
int cmpname(char *, const char *);
void signal_handler(int sig);
void _putchar(char c);
void free_list(env_t *head);
char *get_pid(void);
info_t init_main(int argc, char *argv[], char *envp[]);
#endif
