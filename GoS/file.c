#include "shell.h"

/**
 * check_built_ins - checks to see if command is a built in
 * @cmd: command passed to main
 * @args: arguments passed with command
 * Return: returns 0 on success, 1 on failure.
 */
int check_built_ins(char *cmd, char **args)
{

	if (_strcmp(cmd, "cd") == 0)
		change_directory(args);
	else if (_strcmp(cmd, "setenv") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "unsetenv") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "exit") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "env") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "history") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "help") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "alias") == 0)
		/* TODO */;
	else if (_strcmp(cmd, "unalias") == 0)
		/* TODO */;
	else
		return (1);

	return (0);
}

/**
 * check_path - checks PATH directories for existance of command
 * @cmd: command to check for
 * Return: 0 on success; 1 on failure
 */

int check_path(char *cmd, char **args, path_t *path_head)
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
		strncat(file_path, cmd, _strlen(cmd));
		strcat(file_path, "\0");
		if (access(file_path, X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(file_path, args, environ);
			else if (pid < 0)
			{
				perror("Error");
				return (1);
			}
			else
			{
				wait(&status);
			}
			free(file_path);
			return (0);
		}
		free(file_path);
		temp = temp->next;
	}
	return (1);
}
