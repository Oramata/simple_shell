#include "shell.h"

/**
 * execute_command - Executes the provided command.
 * @command: The command to be executed.
 *
 * Description: Checks if the command exists and forks a new process
 * to execute the command if found.
 */
void execute_cmd(char **command)
{
	char **argv = malloc(2 * sizeof(char *));
	pid_t pid;
	if (argv == NULL)
	{
		argv[0] = command[0];
		argv[1] = NULL;

		pid = fork();
		if (pid == 0)
		{
			/* Child process */
			execv(command[0], argv);
			perror("execv");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			/* Parent process */
			int status;
			wait(&status);
		}
		else
		{
			perror("fork");
		}
		free(argv);
	}
	else
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
}
