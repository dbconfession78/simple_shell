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

typedef struct info_s
{
//	env_t *env;
	char **args;
	path_t *path_head;
	char *line;
} info_t;

void set_prompt(void);
char *_getenv(char *var_name);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
void _putchar(char c);
path_t *list_tokenized_path(char *path);
path_t *add_path_node_end(path_t **head, char *path_dir);
env_t *add_env_node(env_t **head, const char *env_var);
env_t *_setenv(char *name, char *value, env_t **head);
void free_path_list(path_t *head);
void signal_handler(int sig);
void set_prompt(void);
char **tokenize_stdin(char *line);
int exec_builtin_cmd(char *cmd, char **args, info_t *info);
int exec_path_cmd(char *cmd, char **args, path_t *path_head);
int change_directory(char *dir, char **args);
void init_shell (info_t *info);
void print_env(void);
#endif
