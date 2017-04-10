#include "shell.h"

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
