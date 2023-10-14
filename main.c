#include "shell.h"

/**
 * main - Entry point for the shell
 * Description: Keeps the shell running,
 * displaying prompt and executing commands.
 * Return: 0 on success (though it's an infinite loop so return not expected)
 */
int main(void)
{
	char *line;
	char *command;

	while (1)
	{
		display_prompt();
		line = read_input();
		command = parse_input(line);
		execute_command(command);
		free(line);
	}

	return (0);
}
