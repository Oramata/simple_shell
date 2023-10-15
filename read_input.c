#include "shell.h"

/**
 * read_input - Reads the user's input
 * Return: The user's input as a string
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}
