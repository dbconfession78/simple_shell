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
#include <sys/wait.h>

#define PROMPT "🔥  " 
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
 * @name: env variable name
 * @value: env variable value
 * @next: pointer to next node in list
 */
typedef struct env_s
{
	char *name;
	char *value;
	struct env_s *next;
} env_t;

/**
 * struct info_s - struct for shell variables
 * @env_head: pointer to head of env_t list
 * @path_head: pointer to the head of path_t list
 * @line: pointer to arguments received in getline
 */

typedef struct info_s
{
	env_t *env_head;
	path_t *path_head;
	char *line;
} info_t;

void set_prompt(void);
env_t *_getenv(char *var_name, env_t *head);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
void _putchar(char c);
path_t *list_tokenized_path(char *path);
path_t *add_path_node_end(path_t **head, char *path_dir);
env_t *add_env_node(env_t **head, char *name, char *value);
env_t *_setenv(char *name, char *value, env_t *head);
void free_path_list(path_t *head);
void signal_handler(int sig);
void set_prompt(void);
char **tokenize_stdin(char *line);
int exec_builtin_cmd(char *cmd, char **args, info_t *info);
int exec_path_cmd(char *cmd, char **args, path_t *path_head, info_t *info);
int change_directory(char *dir, char **args, info_t *info);
void init_shell(info_t *info);
int print_env(env_t **head, info_t *info);
char **alloc_grid(int height);
env_t *init_env_list(char **environ, env_t **head);
void exit_shell(char *exit_status, char **args, info_t *info);
char **env_list_to_array(env_t *env_head);
int free_string_array(char **array);
int _atoi(char *s);
void free_info(info_t *info);
void free_env_list(env_t *head);
char *_strncat(char *dest, char *src, size_t n);
int exec_filename(char *cmd, char **args);
#endif
