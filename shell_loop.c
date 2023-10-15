#include "shell.h"

/**
 * shell_loop - Main loop of the shell
 */
void shell_loop(void)
{
	char *line = NULL;
	char **command;
	int status = 1;
	int i;

	do {
		printf("#cisfun$ ");
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

		execute_command(command);

		free(line);
		for (i = 0; command[i] != NULL; i++) {
			free(command[i]);
		}
		free(command);
	}
	while (status);
}
