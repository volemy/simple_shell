#include "main.h"

/**
 *_getenv - Searches for specified environment variable.
 *@name: The desired environment variable
 *
 *Return: Pointer to the value associated with the variable
 *	   or NULL if not found
 */

char *_getenv(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0 &&
				environ[i][_strlen(name)] == '=')
		{
			return (environ[i] + _strlen(name) + 1);
		}
	}

	return (NULL);
}

/**
 *print_environment - Prints the current environment
 */

void print_environment(void)
{
	while (*environ != NULL)
	{
		write(1, *environ, _strlen(*environ));
		write(1, "\n", 1);

		environ++;
	}
}

/**
 *capture_original_environment - Captures the original environment
 *
 *Return: Pointer to the copy
 */

char **capture_original_environment(void)
{
	char **original_environ = NULL;
	int environ_count = 0, i;

	while (environ[environ_count] != NULL)
		environ_count++;

	original_environ = (char **)malloc((environ_count + 1) * sizeof(char *));
	if (!original_environ)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < environ_count; i++)
	{
		original_environ[i] = _strdup(environ[i]);
		if (!original_environ[i])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
	}
	original_environ[environ_count] = NULL;

	return (original_environ);
}

/**
 *free_original_environment - frees the memory
 *@original_environ: Pointer to the array
 */

void free_original_environment(char **original_environ)
{
	int i;

	if (original_environ)
	{
		for (i = 0; original_environ[i] != NULL; i++)
			free(original_environ[i]);
		free(original_environ);
	}
}

