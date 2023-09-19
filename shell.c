#include "main.h"

/**
 * splitArguments - function that handles arguments
 * @input: takes input of user
 * @args: array that holds arguments.
 */

void splitArguments(char *input, char *args[])
{
	int arg_count = 0;

	args[arg_count] = _strtok(input, " ");
	while (args[arg_count] != NULL)
	{
		arg_count++;
		args[arg_count] = _strtok(NULL, " ");
	}

	args[arg_count] = NULL;
}

/**
 *main - a UNIX command line interpreter
 *@argc: The number of command-line arguments
 *@argv: An array of strings representing the command-line arguments
 *
 *Return: 0 when successful or 1 when otherwise
 */

int main(int argc, char *argv[])
{
	size_t input_len = 0;
	char *input = NULL;

	(void)argv;

	if (isatty(STDIN_FILENO) && argc == 1)
	{
		while (1)
		{
			char prompt[] = "simple_shell$ ";

			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

			getline(&input, &input_len, stdin);
			input[_strlen(input) - 1] = '\0';

			if (_strcmp(input, "exit") == 0)
				break;
			else if (_strncmp(input, "exit ", 5) == 0)
			{
				char *status_str = input + 5;
				int status_code = _atoi(status_str);

				if (status_code != 0 || _strcmp(status_str, "0") == 0)
					exit(status_code);
			}

			handleCommand(input);
		}
	}
	else
	{
		while (getline(&input, &input_len, stdin) != -1)
		{
			input[_strlen(input) - 1] = '\0';
			handleCommand(input);
		}
	}
	free(input);
	return (0);
}
