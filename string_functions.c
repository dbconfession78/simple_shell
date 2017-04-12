#include "shell.h"

/**
 * _strlen - returns the length of a string
 *
 *@s: character array to count
 *
 * Return: number of characters
 */

int _strlen(const char *s)
{
	int i, c;

	i = 0;
	c = -1;
	while (c != 0)
	{
		c = s[i];
		if (c != 0)
		{
			i++;
		}
	}
	return (i);
}

/**
 * _strcpy - copies the string pointed to by src to the buffer pointed to by
 * dest.
 *
 *@dest: src is copied into here
 *@src: copied into dest
 *
 * Return: pointer to the dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		if (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		if (src[i] == 0)
		{
			dest[i] = '\0';
		}
	}
	return (dest);
}

/**
 * _strcmp - compares two strings for equality
 *
 * @s1: first string in comparison
 * @s2: second string in comparison
 *
 * Return: 0 if equal; 1 if not equal
 */

int _strcmp(char *s1, char *s2)
{
	for ( ; *s1 && (*s1 == *s2); s1++, s2++)
		;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
