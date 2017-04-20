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
/**
* _strncat - concatenates two string up to n bytes
* @src: first string
* @dest: second string
* @n: number of bytes to concatenate
* Return: Pointer to dest string
*/
char *_strncat(char *dest, char *src, size_t n)
{
	size_t i, dlen = _strlen(dest);

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dlen + i] = src[i];
	dest[dlen + i] = '\0';
	return (dest);
}

/**
 * print_unsigned_int - writes integer to
 * standard output
 * @num: unsigned int
 * Return: nothing
 */

void print_unsigned_int(int num)
{
	int digit;

	if (num / 10 != 0)
	{
		print_unsigned_int(num / 10);
	}

	digit = ((num % 10) + '0');

	(write(1, &digit, 1));
}
