#include "shell.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * shell_loop - Main loop of the shell
 */
void shell_loop(void)
{
	char *line
	char **commands;
	int status = 0;

	while (1)
	{
		display_prompt();
		line = read_input();
		if (!line)
		{
			if (feof(stdin))
			{
				/* Handle EOF */
				printf("\n");
				break;
			} else {
				/* Handle read error */
				perror("readline");
				continue;
			}
		}

		commands = parse_input(line);
		if (commands)
		{
			status = execute_command(commands);
		}

		free(line);
		if (commands)
		{
			for (i = 0; commands[i] != NULL; i++)
			{
				free(commands[i]);
			}
			free(commands);
		}
	}
}
