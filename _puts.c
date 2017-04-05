#include "headers.h"

/**
 * _puts - prints a string
 *
 *@str: string to print
 *
 * Return: void
 */

void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
