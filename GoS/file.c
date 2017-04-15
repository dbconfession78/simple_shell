/**
 * check_builtins - checks to see if command is a built in
 * @cmd: command passed to main
 * @args: arguments passed with command
 * Return: returns 0 on success, 1 on failure.
 */
int check_builtins(char *cmd, char **args)
{

	if (_strcmp(cmd, "cd") == 0)
		/* TODO*/;
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
