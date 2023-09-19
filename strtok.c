#include "main.h"

/**
 * _strtok - splits a string into tokens
 * @line: the string to split
 * @delim: the delimiter to use
 *
 * Return: a pointer to the array of tokens
 */

char *_strtok(char *line, char *delim)
{
	static char *str = NULL;
	char *copystr;

	if (line != NULL)
		str = line;

	while (*str != '\0' && _strchr(delim, *str) != NULL)
		str++;

	if (*str == '\0')
		return (NULL);

	copystr = str;

	while (*str != '\0' && _strchr(delim, *str) == NULL)
		str++;

	if (*str != '\0')
		*str++ = '\0';

	return (copystr);
}
