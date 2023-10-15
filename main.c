#include "shell.h"

/**
 * main - Entry point for the shell
 * Description: Keeps the shell running,
 * displaying prompt and executing commands.
 * Return: 0 on success (though it's an infinite loop so return not expected)
 */
int main(void)
{
	char *command[256];

	command[0] = malloc(256 * sizeof(char));
	if (command[0] == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	printf(":) ");

	while (fgets(command[0], 256, stdin) != NULL)
	{
		command[0][strcspn(command[0], "\n")] = 0;
		execute_command(command);
		printf(":) ");
	}
	free(command[0]);
	return (0);
}
