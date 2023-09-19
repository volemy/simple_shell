#include "main.h"

/**
 * exit_status - function that handles arguments
 * @input: takes input of user
 */

void exit_status(char *input)
{
	char *status_str = input + 5;
	int status_code = _atoi(status_str);

	if (status_code != 0 || _strcmp(status_str, "0") == 0)
		exit(status_code);
}
