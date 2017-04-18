![printf](PLACE IMAGE URL HERE)

# Welcome to The Gates of Shell (GoS)

SYNOPSIS
————

This is a custom implementation of the UNIX `shell` command-line interface. The objective of this project is to exercise the authors’ understanding of C, gain further familiarity with the operations of the shell, and manage increased program complexity.

More specific goals include:
- understanding what a pid and a ppid are
- learning how to manipulate the environment of the current process
- understanding the difference between a function and a system call
- learning how to create processes
- learning what the three prototypes of main are
- understanding how the shell uses the PATH to find programs
- learning how to execute another program with the execve system call
- learning how  to suspend the execution of a process until one of its children terminates
- understanding what and how EOF / "end-of-file" works

# COLLABORATORS (Holberton School Batch 2)
--------

Stuart Kuredjian - https://github.com/dbconfession78 || [Twitter](https://twitter.com/StueyGK)

Jared Heck - https://github.com/jarehec || [Twitter](https://twitter.com/jarehec)

Max Johnson - https://github.com/j31508 || [Twitter](https://twitter.com/MBJohnson31)

Spencer Cheng - https://github.com/spencerhcheng || [Twitter](https://twitter.com/spencerhcheng)


## COMPILATION AND USAGE

```
$ git clone [repository link]
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./hsh

[enter following shell commands]
```

## PROJECT REQUIREMENTS

- Code compliance with [Betty](https://github.com/holbertonschool/Betty) style and document guidelines.
- Code compiled using flags: `-Wall`, `-Werror`, `-Wextra`, `-pedantic
- Restricted to no more than 5 functions per file.
- Header files should be include guarded.

- AUTHORIZED FUNCTIONS:

```
- access
- chdir
- close
- closer
- exec
- exit
- fork
- free
- stat
- getcwd
- get line
- kill
- stat
- malloc
- open
- opendir
- perror
- read
- readdir
- signal
- stat
- strtok
- wait
- waitpid
- wait3
- wait4
- write
- _exit

```

# GoS

### HANDLED COMMANDS

#### PATH COMMANDS
GoS shell will handle commands whose executable files (i.e. ready-to-run programs) reside in the PATH environmental variable. PATH specifies a set of directories where executable programs are located:

```
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
```

## TO DO

### Handle the following conversion specifiers:
- [ ] | - `piping`


# FUNCTIONS

```
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
```
