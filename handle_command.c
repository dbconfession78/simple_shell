#include "shell.h"

int is_builtin()
{

}

int is_in_path()
{


}

void handle_command(char **tokens)
{
	char *dir = "/bin/";
	int size = sizeof(char) * (strlen(dir) + strlen(tokens[0]) + 1);
	char *path = malloc(size);
	pid_t pid;

	strcpy(path, dir);
	strncat(path, tokens[0], strlen(tokens[0]));
	strcat(path, "\0");

	pid = fork();
	if (pid == 0)
	{
		printf("exec success: %d\n", execve(path, tokens, NULL));
	}
	else if (pid < 0)
	{
		printf("pid: less than 0");
	}
	else
	{
		wait();
	}
}
