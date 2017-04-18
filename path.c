#include "shell.h"

/**
 * exec_builtin_cmd - checks to see if command is a built in
 * @cmd: command passed to main
 * @args: arguments passed with command
 * @info: the info_t struct
 * Return: returns TRUE (1) on success, FALSE (0) on fail.
 */
int exec_builtin_cmd(char *cmd, char **args, info_t *info)
{
	if (!cmd)
		return(TRUE);
	if (_strcmp(cmd, "cd") == 0)
		change_directory(args[1], args, info);
	else if (_strcmp(cmd, "exit") == 0)
		exit_shell(NULL, args, info);
	else if (_strcmp(cmd, "env") == 0)
		print_env(&info->env_head, info);
	else if (_strcmp(cmd, "setenv") == 0)
		_setenv(args[1], args[2], info->env_head);
	else if (_strcmp(cmd, "unsetenv") == 0)
		; /* TODO */
	else if (_strcmp(cmd, "history") == 0)
		; /* TODO */
	else if (_strcmp(cmd, "help") == 0)
		; /* TODO */
	else if (_strcmp(cmd, "alias") == 0)
		; /* TODO */
	else if (_strcmp(cmd, "unalias") == 0)
		; /* TODO */
	else
		return (FALSE);
	return (TRUE);
}

/**
 * exec_path_cmd - checks/executes commandss in the PATH directories
 * @cmd: command to check for
 * @args: arguments received by getline
 * @path_head: pointer to first node of path_t list
 * @info: pointer to shell information struct
 * Return: TRUE (1) on success; FALSE (0) on failure
 */
int exec_path_cmd(char *cmd, char **args, path_t *path_head, info_t *info)
{
	path_t *temp;
	char *file_path;
	pid_t pid;
	int status;
	char **env_array;

	temp = path_head;
	while (temp->next)
	{
		file_path = malloc(sizeof(char) * (_strlen(temp->path_dir) +
										   _strlen(cmd) + 1));
		_strcpy(file_path, temp->path_dir);
		_strncat(file_path, cmd, _strlen(cmd)); /* create custom _strncat(...)*/
		_strcat(file_path, "\0");
		if (access(file_path, X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				env_array = env_list_to_array(info->env_head);
				execve(file_path, args, env_array);
			}
			else if (pid < 0)
			{
				perror("Error");
				exit(1000); /*TODO: handle exit values */
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
/**
 * exec_filename - checks/executes commands
 * @cmd: command to check for
 * @args: arguments received by getline
 * Return: TRUE (1) on success; FALSE (0) on failure
 */
int exec_filename(char *cmd, char **args)
{
	pid_t pid;
	int status;

	if (access(cmd, X_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(cmd, args, environ);
		}
		else if (pid < 0)
		{
			perror("Error");
			exit(1000); /*TODO: handle exit values */
		}
		else
		{
			wait(&status);
		}
		return (TRUE);
	}
	return (FALSE);
}
