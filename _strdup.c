#include "shell.h"
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
/*	for (i = 0; str[i] != '\0'; i++)
		p_str[i] = str[i];
*/
	_strcpy(p_str, str);
	return (p_str);
}

/*
char *_strdup(char *str)
{
	char *dupe;

	if (str == NULL)
		return (NULL);
	dupe = mloc(_strlen(str) + 1, NULL);
	if (dupe == NULL)
		return (NULL);
	_strcpy(dupe, str);
	return (dupe);
}
*/
