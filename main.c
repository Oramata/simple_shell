#include "shell.h"

/**
 * main - Entry point for the shell
 * Description: Keeps the shell running,
 * displaying prompt and executing commands.
 * Return: 0 on success (though it's an infinite loop so return not expected)
 */
int main(void)
{
	char *line = NULL;
	char **command = parse_input(line);
	int i;

	while (1)
	{
		display_prompt();
		line = read_input();
		if (!line)
		{
			perror("Error reading input");
			continue;
		}
		command = parse_input(line);
		if (!command)
		{
			perror("Error parsing input");
			free(line);
			continue;
		}
		execute_command(command);
		free(line);
		/* Assuming command ia a NULL-terminated array of strings */
		for (i = 0; command[i] != NULL; i++)
		{
			free(command[i]);
		}
		free(command);
	}

	return (0);
}
