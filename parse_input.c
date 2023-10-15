#include "shell.h"

/**
 * parse_input - Parses the user's input into an array of arguments
 * @line: The user's input
 * Return: An array of arguments
 */

char **parse_input(char *line)
{
	char **command = malloc(MAX_ARG * sizeof(char *));
	char *token;
	int index = 0;

	if (command == NULL)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n");
	while (token != NULL && index < MAX_ARG)
	{
		command[index] = token;
		index++;
		token = strtok(NULL, " \n");
	}
	command[index] = NULL;

	return (command);
}
