![printf](http://i.imgur.com/FBKO2yt.png)

![printf](http://i.imgur.com/CsfTB2F.jpg)

#### Gates of Shell (GoS) is a simple command line shell for UNIX and Linux. GoS includes most basic features that are standard in bash shell.


## SYNOPSIS

GoS is a custom implementation of the UNIX `shell` command-line interface. The objective of this project is to exercise the authors’ understanding of C, gain further familiarity with the operations of the shell, and manage increased program complexity.

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

## COLLABORATORS (Holberton School Batch 2)

Stuart Kuredjian - https://github.com/dbconfession78 || [Twitter](https://twitter.com/StueyGK)

Jared Heck - https://github.com/jarehec || [Twitter](https://twitter.com/jarehec)

Max Johnson - https://github.com/j31508 || [Twitter](https://twitter.com/MBJohnson31)

Spencer Cheng - https://github.com/spencerhcheng || [Twitter](https://twitter.com/spencerhcheng)


## PROJECT REQUIREMENTS

- Code compliance with [Betty](https://github.com/holbertonschool/Betty) style and document guidelines.
- Code compiled using flags: `-Wall`, `-Werror`, `-Wextra`, `-pedantic
- Restricted to no more than 5 functions per file.
- Header files should be include guarded.


## COMPILATION AND USAGE
GCC 4.8.5 compiler or later.

```
$ git clone [repository link]
$ gcc -Wall -Werror -Wextra -pedantic *.c -o GoS
./GoS

[enter following shell commands]
```

#### SYNTAX OVERVIEW

------

GoS commands follows the general syntax: `command name {arguments}`. The command is executed by writing the name of the command followed by any arguments.

```
echo Hello
```

Above will run the `echo` command, which will write its arguments `Hello` to  the standard output.

For more information on echo, you can use the `man` command. The `man` command displays a manual page of a given command, system call, libraries, and important files.

```
man echo
```

The GoS shell also provides various builtins, commands built into the GoS shell itself. For more information on specific builtins, you can use the `help` command, which provides a similar manual for the specific builtin.

```
help setenv
```

Supported syntax and lists of builtins and commands are given in their respected sections.

#### Commands

------

Any program in your computer can be used as a command in GoS. If the program is located in any of the directories in the [PATH - link include], then typing the filename is enough to run the command. Otherwise, a full path to the program is required

```
/Desktop/Holberton/my_echo Hello Holberton
```

##### Command Seperation

Commands and any arguments are seperated by a ` ' '` . Commands end with either a newline (i.e Return Key) or a `;`, `&&`, or `||`.

To enter more than one command in one line, a `;` can be used to seperate commands. Commands are read and executed left to right.

```
echo Hello Holberton ; ls
```

If commands are seperated by `&&` , the leftmost command is read and executed and if the execution failed, no other commands are executed, otherwise, the next command in line will be executed. If the commands is seperated by `||` , regardless of execution failure or success of the leftmost command, all suceeded commands are executed.

##### Switches & Flags

Switches and flags arguements of commands are also supported by GoS. Most switches start with a hypen, `-`  and always somehows affect the command in one way. For example, when a user inputs:

```
ls -a
```

The `ls` commands lists all directories and files in the current working directory. However, including the switch `-a` , will also include all files and directories, including hidden ones.

##### Comments

GoS provides support for comments added into standard input. Comments can be inputed by placing a `#` before any statement. Comments are ignored by GoS.

```
echo # Hello Holberton
```

The above command will not write Hello Holberton to standard output.

##### List of useful commands

`cat` - concatenate and print files to standout output

`cp` - copy files to another file

`grep` - searches a file for a specified pattern

`less` - allows backward moveement in the file as well as foward movement

`ls` - lists all files and directories of current working directory

`mv` - moves one file into another file

`pwd` - prints out the current working directory

### Builtins

------

There are several builtins programmed into the GoS. Below is a description and use for each builtin.

##### env, setenv, unsetenv

To print out a list of all the environemental variables, the builtin `env` can be used. Each environmental variable and its value is printed out with a syntax of `key=value`. Each variable is seperated by a new line.

To set an environemental variable, the builtin is `setenv`. The syntax to use `setenv` is `setenv key value`. If one of the arguments is missing, an error is returned.

```
setenv holberton betty
```

To remove an environemental variable, the builtin `unsetenv` can be used. The syntax to use `unsetenv` is `unsetenv key`. If no `key` value is given, an error is returned.

```
unsetenv holberton
```

##### cd

The `cd` command changes the shell working directory. The syntax to use the command is `cd DIR`. If no `DIR` is given, it is defaulted to the HOME shell variable. The full path of the directory is needed. To change the directory to its parent, the argument `..` can be used.

##### history

To print out a list of previous commands used, the command `history` can be used. The previous 50 commands will be printed out. The history of all commands is written into the `.simple_shell_history` file.

##### help

To receive a description and the syntax use of a specific command, you can use the `help` command. To use the `help` builtin, the synatax is as follows

```
help cd
```

The output would include usage followed by a definition.

```
cd usage: cd DIR
	Change the current directory to DIR
```

### exit

To exit out of the shell, the user may use the `exit` builtin or press CTRL + D. Exit with status is not supported.

```
exit 1
```

### Exiting commands and GoS

------

To exit out of a process or command, `ctrl c` is used. Control-C interrupts a process and causes it to abort.

To exit out of the GoS shell, the user can do one of the following, `ctrl D` or `exit n`. When exiting with `ctrl D`, an exit status of 0 is given. Using `exit`, you can input its exit status or it is defaulted to the status of the last command executed.

## Project Purpose
This project's purpose is to:
- understand how a shell works
- learn how to build a shell
- understand what a pid and an ppid are
- learn how to manipulate the environment of the current process
- understand the difference between a function and a system call
- learn how to create processes
- learn what the three prototypes of main are
- understand how the shell uses the PATH to find programs
- learn How to execute another program with the execve system call
- learn how  to suspend the execution of a process until one of its children terminates
- understand what and how EOF / "end-of-file" works?

## Project requirements
- Code compliance with [Betty](https://github.com/holbertonschool/Betty) style and document guidelines.
- Code compiled using flags: `-Wall`, `-Werror`, `-Wextra`, `-pedantic
- Restricted to no more than 5 functions per file.
- Header files should be include guarded.
- Authorized functions and macros:
..* `XXX` (`man X XXX`)

..* program must have the exact same output as sh as long as the exact same error output.

## File Descriptions
- `shell.h`: contains the prototypes for each corresponding .c function file
- `main.c`: The entry point for the shell
- `memory.c`: memory allocation that frees all elements of info_t struct, a list_t, env_t list, and a double pointer
- `path.c`: File that checks for built-in commands.
- `path_list.c`: Contains checks to see if command is a built in
- `string_functions_1.c`: Custom strlen function
- `string_functions_2.c`: Custom function that prints a string
## Authors

*Stuart Kuredjian* - [Github](https://github.com/dbconfession78) || [Twitter](https://twitter.com/StueyGK) || [LinkedIn](https://www.linkedin.com/in/stuart-kuredjian-8100a273/)

*Jared Heck* - [Github](https://github.com/ajrehec) || [Twitter](https://twitter.com/XXXXX?????) || [LinkedIn](https://www.linkedin.com/in/jared-heck-28a469133/)

*Spencer Cheng* - [Github](https://github.com/spencerhcheng) || [Twitter](https://twitter.com/spencerhcheng)] || [LinkedIn](https://www.linkedin.com/in/spencer-cheng-284b4b55/)

*Max Johnson* - [Github](https://github.com/mj31508) || [Twitter](https://twitter.com/MBJohnson31) || [LinkedIn](https://www.linkedin.com/in/max-johnson-697282b4/)


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

## GoS

## COMMANDS HANDLED

#### PATH COMMANDS
GoS shell will resolve commands whose executable files (i.e. ready-to-run programs) reside in the PATH environmental variable. PATH specifies a set of directories where executable programs are located:

```
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
```

## TO DO

### Handle the following conversion specifiers:
- [ ] | - `piping`
- [ ] | - `exit with status`
- [ ] | - `write custom getline`
- [ ] | - `write custom strtok`
- [ ] | - `handle command separator ;`
- [ ] | - `handle && and || logical operators`
- [ ] | - `handle aliases`
- [ ] | - `handle variable replacement`
- [ ] | - `handle $? and $$ variable`
- [ ] | - `handle comments (#)`

## FUNCTIONS

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
