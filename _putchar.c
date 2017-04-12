#include "shell.h"

/**
 * _putchar - prints a character
 *
 * @c: character to print
 *
 * Return: void
 */

void _putchar(char c)
{
	write(1, &c, 1);
}
