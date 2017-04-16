#include "shell.h"

/**
 * exec_builtin_cmd - checks to see if command is a built in
 * @cmd: command passed to main
 * @args: arguments passed with command
 * Return: returns TRUE (1) on success, FALSE (0) on fail.
 */
int exec_builtin_cmd(char *cmd, char **args, info_t *info)
{
	if (_strcmp(cmd, "cd") == 0)
		change_directory(args[1], args);
	else if (_strcmp(cmd, "setenv") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "unsetenv") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "exit") == 0)
		exit_shell(NULL, info);
	else if (_strcmp(cmd, "env") == 0)
		print_env();
	else if (_strcmp(cmd, "history") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "help") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "alias") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "unalias") == 0)
		/* TODO */;
	else
		return (FALSE);

	return (TRUE);
}

/**
 * check_path - checks PATH directories for existance of command
 * @cmd: command to check for
 * Return: TRUE (1) on success; FALSE (0) on failure
 */

int exec_path_cmd(char *cmd, char **args, path_t *path_head)
{
	path_t *temp;
	char *file_path;
	pid_t pid;
	int status;

	temp = path_head;
	while (temp->next)
	{
		file_path = malloc(sizeof(char) * (_strlen(temp->path_dir) +
										   _strlen(cmd) + 1));
		_strcpy(file_path, temp->path_dir);
		strncat(file_path, cmd, _strlen(cmd)); /* create custom _strncat(...)*/
		strcat(file_path, "\0");
		if (access(file_path, X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(file_path, args, environ);
			else if (pid < 0)
			{
				perror("Error");
				exit (1000); /*TODO: handle exit values */
			}
			else
			{
				wait(&status);
			}
			free(file_path);
			return (TRUE);
		}
		free(file_path);
		temp = temp->next;
	}
	return (FALSE);
}
