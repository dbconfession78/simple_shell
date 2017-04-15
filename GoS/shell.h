#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define PROMPT "$ "
#define TRUE 1
#define FALSE 0

extern char **environ;
/**
 * struct path_s - struct for path directory
 * @path_dir: path directory
 * @next: pointer to next node in list
 */
typedef struct path_s
{
	char *path_dir;
	struct path_s *next;
} path_t;

/**
 * struct env_s - struct for env variable
 * @env_var: name and value of env variable
 * @next: pointer to next node in list
 */
typedef struct env_s
{
	char *env_var;
	struct env_s *next;

} env_t;

void set_prompt(void);
char *_getenv(char *var_name);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
path_t *list_tokenized_path(char *path);
path_t *add_path_node_end(path_t **head, char *path_dir);
void free_path_list(path_t *head);
void signal_handler(int sig);
void set_prompt(void);
char **tokenize_stdin(char *line);
int check_builtins(char *cmd, char **args);

#endif
