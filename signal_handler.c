#include "shell.h"

void signal_handler(int sig)
{
	char *cwd;
	write(0, "\n", 1);
	set_prompt();

}
