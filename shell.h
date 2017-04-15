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

typedef struct path_s
{
	char *dir;
	struct path_s *next;
} path_t;
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
void free_list(env_t *head);
char *get_pid(void);
info_t init_main(int argc, char *argv[], char *envp[]);
int init_path(void);
path_t *add_pathnode_end(path_t **head, const char *str);
path_t *path_list(char *list, path_t *head);
char *_getenv(const char *name);
void free_path(path_t *head);
/* string functions */
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
void _putchar(char c);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
#endif
