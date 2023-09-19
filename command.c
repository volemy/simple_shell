#include "main.h"

/**
 * findCommand - find the full path of the command
 * @command: the command to find
 * @executable_path: the PATH environment variable
 *
 * Return: the full path of the command, or NULL if the command does not exist
 */

char *findCommand(const char *command, char *executable_path)
{
	char *path_env, path_copy[MAX_PATH_LENGTH], *path_token;

	if (_strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			return (_strdup(command));
		}
		return (NULL);
	}
	path_env = _getenv("PATH");
	if (path_env == NULL)
	{
		char error_msg[] = "PATH environment variable not found. \n";

		write(2, error_msg, sizeof(error_msg) - 1);
		return (NULL);
	}
	_strncpy(path_copy, path_env, sizeof(path_copy) - 1);
	path_copy[sizeof(path_copy) - 1] = '\0';
	path_token = _strtok(path_copy, ":");
	while (path_token != NULL)
	{
		size_t path_len = _strlen(path_token);
		size_t command_len = _strlen(command);

		if (path_len + command_len + 2 <= MAX_PATH_LENGTH)
		{
			_strcpy(executable_path, path_token);
			_strcat(executable_path, "/");
			_strcat(executable_path, command);
			if (access(executable_path, X_OK) == 0)
				return (_strdup(executable_path));
		}
		path_token = _strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * executeCommand - execute the given command with arguments
 * @full_path: the full path of the command
 * @args: array of arguments
 */

void executeCommand(const char *full_path, char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
		perror("fork");
	else if (child_pid == 0)
	{
		if (execve(full_path, args, NULL) == -1)
		{
			char error_msg[] = "./shell: No such file or directory\n";

			write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(child_pid, &status, 0);
}

/**
 * handleCommand - handle user command
 * @input: user input
 */

void handleCommand(char *input)
{
	char *args[2], **original_environ = capture_original_environment();
	char *path, *full_path, executable_path[MAX_PATH_LENGTH];
	int i;

	if (_strcmp(input, "env") == 0)
	{
		for (i = 0; original_environ[i] != NULL; i++)
		{
			size_t len = _strlen(original_environ[i]);

			write(STDOUT_FILENO, original_environ[i], len);
			write(STDOUT_FILENO, "\n", 1);
		}
	}

	splitArguments(input, args);

	path = _getenv("PATH");
	if (!path)
	{
		char error_msg[] = "./shell: PATH environment variable not found.\n";

		write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
		return;
	}

	full_path = findCommand(args[0], executable_path);
	if (!full_path)
	{
		char error_msg[128];

		_strcpy(error_msg, "./shell: Command not found: ");
		_strcat(error_msg, args[0]);
		_strcat(error_msg, "\n");
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		return;
	}
	executeCommand(full_path, args);
	free_original_environment(original_environ);
	free(full_path);
}
