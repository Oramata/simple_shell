#include "shell.h"

/**
 * read_input - Reads a line of input from the user.
 * Description: Utilizes getline to read user input.
 * Return: The line read from the user.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		exit(0);
	}
	return (line);
}

/**
 * parse_input - Parses the input to extract the command.
 * @line: The line of input to be parsed.
 * Description: Uses strtok to tokenize the input,
 * and extract the command.
 * Return: The command extracted from the input.
 */
char *parse_input(char *line)
{
	char *command;
	command = strtok(line, " \n");
	return (command);
}
