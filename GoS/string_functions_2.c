#include "shell.h"

/**
 * _puts - prints a string
 *@str: string to print
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != 0)
		_putchar(str[i++]);
	_putchar('\n');
}

/**
 * _putchar - prints a character
 *@c: character to print
 * Return: void
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _atoi - converts a string with numbers into an int
 *@s: string to convert
 * Return: int converted fro string
 */
int _atoi(char *s)
{
	int i;
	int result;
	int neg_count;

	result = neg_count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			neg_count++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			for ( ; s[i] >= '0' && s[i] <= '9'; i++)
				result = result * 10 - (s[i] - '0');
			break;
		}
	}
	if (neg_count % 2 == 0)
		result *= -1;
	else
		result *= 1;
	return (result);
}
