#include "headers.h"
/**
 * _strdup - returns a pointer to a newly allocated space in mem
 * which contains a copy of string givem as a param
 *
 * @str: string copied into mem location being pointed to
 *
 * Return: pointer to mem location containing copy if string
 */

char *_strdup(const char *str)
{
	unsigned int i;
	int len = _strlen(str) + 1;
	char *p_str;

	if (str == NULL)
		return (NULL);
	p_str = malloc(len * sizeof(char));
	for (i = 0; str[i] != '\0'; i++)
		p_str[i] = str[i];
	return (p_str);
}
