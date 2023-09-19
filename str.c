#include "main.h"

/**
 *_strchr - Locates a character in a string
 *@s: The String being used
 *@c: The character being located.
 *Return: 0
 */

char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}

	return (NULL);
}

/**
 *_strlen - Returns the length of a string
*@s: The string being used
 *Return: Returns the length of the string
*/

int _strlen(const char *s)
{
	unsigned int len = 0;
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
		len += sizeof(char);

	return (len);
}

/**
 * _strcpy - copies a string from src to dest
 * @dest: destination
 * @src: source
 *
 * Return: dest/copied string
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}


/**
 *_strdup - Copies a String given as a parameter
 *@str: The string to be copied
 *Return: A pointer to the new string on Success
 */

char *_strdup(const char *str)
{
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = malloc(_strlen(str) + 1);

	if (dup == NULL)
		return (NULL);

	_strcpy(dup, str);

	return (dup);
}

/**
 *_strcat - adds to strings
 *@dest: destination
 *@src: source
 *Return: dest
 */

char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (*(dest + i) != '\0')
		i++;

	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
