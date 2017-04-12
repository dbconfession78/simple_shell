#include "shell.h"

/**
 * set_prompt - puts '$ ' prompt to the screen
 * Return: void
 */

void set_prompt(void)
{
	write (STDOUT_FILENO, PROMPT, _strlen(PROMPT));
}
