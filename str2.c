#include "main.h"

/**
 *_strncpy - Copies a String
 *@dest: Destination
 *@src: Source
 *@n: The number of bytes
 *Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

/**
 *_strcmp - Compares two strings
 *@s1: The first String
 *@s2: The second string
 *Return: The difference
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: integer
 */

int _atoi(char *s)
{
	int i, j = 0, k = -1;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) == '-')
			k *= -1;
		if (*(s + i) > 47 && *(s + i) < 58)
		{
			if (j < 0)
				j = (j * 10) - (*(s + i) - '0');
			else
				j = (s[i] - '0') * -1;
			if (s[i + 1] < 48 || s[i] > 57)
				break;
		}
	}
	if (k < 0)
		j *= -1;

	return (j);

}

/**
 *_strncmp - Conmpares two strings
 *@s1: A pointer to the first character of the first string
 *@s2: A pointer to the first character of the second string
 *@n: Maximum number of characters to compare
 *
 *Return: 0 if strings are equal, a value < | > than 0 if not equal
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}
