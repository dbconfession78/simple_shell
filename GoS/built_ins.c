#include "shell.h"

/**
 * change_directory - calls cd built-in
 *
 * @args: XXXXXXXXXXXXXXX
 * Return: 1 on success, 0 on failure
 */
int change_directory(char **args)
{
	char *oldcwd, *home, *token;

	token = args[1];
	oldcwd = getcwd(NULL, 100);

	home = (_getenv("HOME"));

	if (token == NULL)
	{
		chdir(home);
		/* TODO _setenv */
/*		_setenv("PWD", home);
		_setenv("OLDPWD", oldcwd);
*/
		free(oldcwd);
		return (1);
	}
	if (token[0] == '-' && token[1] == '\0')
	{
		if (_getenv("OLDPWD"))
		{
			_puts("cd: OLDPWD not set.\n");
			free(oldcwd);
			return (0);
		}

		token = (_getenv("OLDPWD"));
		_puts(token);
		_putchar(10);
	}
	if (chdir(token) != -1)
	{
		/* TODO: _setenv */
		/*_setenv("PWD", token); */
		/*_setenv("OLDPWD", oldcwd); */
		free(oldcwd);
		return (1);
	}
	_puts("cd: Invalid folder.\n");
	free(oldcwd);
	return (0);
}
