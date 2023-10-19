#include "shell.h"

/**
 * shell_loop - Main loop of the shell
 */
void shell_loop(void)
{
	char *line = NULL;
	char **command;
	int i;

	while (1)
	{
		display_prompt();
		line = read_input();
		if (line == NULL) {
			/* Handle error or end of input */
			break;
		}

		command = parse_input(line);
		if (command == NULL) {
			/* Handle error or empty command */
			free(line);
			continue;
		}
		
		/* Check for "exit" built-in */
		if (strcmp(command[0], "exit") == 0)
		{
			free(line);
			for (i = 0; command[i] != NULL; i++)
			{
				free(command[i]);
			}
			free(command);
			exit(0);
		}

		execute_command(command);

		free(line);
		for (i = 0; command[i] != NULL; i++) {
			free(command[i]);
		}
		free(command);
	}
}
