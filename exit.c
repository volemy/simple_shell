#include "main.h"

/**
 * exit_shell -  function that exits the shell
 * @arg: arguments after the exit command
 * Return: (0)
 *
 */
int exit_shell(const char *arg)
{
	if (arg)
	{
		int exit_code = atoi(arg);

		if (exit_code == 0 && arg[0] != 0)
		{

			write(STDERR_FILENO, "Illegal number: ", 16);
			write(STDERR_FILENO, arg, strlen(arg));
			write(STDERR_FILENO, "\n", 1);
			return (1);
		}
		exit(exit_code);
	} else
	{
		exit(0);
	}

	return (0);
}
