#include "shell.h"

/**
 * execute_command - Executes the provided command.
 * @command: The command to be executed.
 */
void execute_command(char **command)
{
	pid_t pid;
	int status;
	char *path;


	if (command == NULL || command[0] == NULL)
	{
		fprintf(stderr, "Command is NULL\n");
		return;
	}

	path = find_command(command[0]);

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		execv(path ? path : command[0], command);
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		/* Parent process */
		wait(&status);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	free(path);
}
