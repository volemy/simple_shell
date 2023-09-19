#ifndef SHELL_H
#define SHELL_H

/**Libraries Used**/
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**Buffers**/
#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024

extern char **environ;

/**Shell Prototypes**/
void splitArguments(char *input, char *args[]);
char *_getenv(const char *name);
char *find_Executable(const char *command, char *executable_path);
void print_environment(void);
void executeCommand(const char *full_path, char *args[]);
void handleCommand(char *input);
char **capture_original_environment(void);
void free_original_environment(char **original_environ);

/**String Prototypes**/
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);
char *_strchr(const char *s, char c);
int _atoi(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strtok(char *line, char *delim);

#endif
