#include "shell.h"

/**
 * read_input - Reads the user's input
 * Return: The user's input as a string
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t read_status;

	read_status = getline(&line, &bufsize, stdin);

	if (read_status == -1)
	{
		if (feof(stdin))
		{
			/* End of file (Ctrl+D) detected */
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
