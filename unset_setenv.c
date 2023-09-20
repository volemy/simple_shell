#include "main.h"

/**
 * my_set_environment - set an environment variable
 * @name: name of the environment variable
 * @value: value to set for the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int my_set_environment(const char *name, const char *value)
{
	if (name == NULL || value == NULL)
	{
		write(STDERR_FILENO, "Argument not found\n", 19);
		return (-1);
	}

	if (setenv(name, value, 1) != 0)
	{
		write(STDERR_FILENO, "Error setting environment", 26);
		write(STDERR_FILENO, name, strlen(name));
		write(STDERR_FILENO, "\n", 1);
		return (-1);
	}
	return (0);
}
/**
 * my_unset_environment - unset an environment variable
 * @name: name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */

int my_unset_environment(const char *name)
{
	if (name == NULL)
	{
		write(STDERR_FILENO, "Argument not found\n", 19);
		return (-1);
	}

	if (unsetenv(name) != 0)
	{
		write(STDERR_FILENO, "Error setting environment", 26);
		write(STDERR_FILENO, name, strlen(name));
		write(STDERR_FILENO, "\n", 1);
		return (-1);
	}
	return (0);
}
