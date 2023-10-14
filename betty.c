#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, error code on failure
 */
int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	init_shell();

	shell_loop();

	return (0);
}

/**
 * init_shell - Initializes the shell environment
 * Return: void
 */
void init_shell(void)
{
	/* Initialization code here */
}

/**
 * shell_loop - Main loop for the shell to read, parse, and execute commands
 * Return: void
 */
void shell_loop(void)
{
	char *line;
	char *command;
	int status = 0;

	do {
		printf("#cisfun$ ");
		line = read_input();
		command = parse_input(line);
		execute_command(command);

		free(line);
	}

	while (status);
}
