#include "shell.h"
#include <sys/wait.h>

/**
 * execute_command - Executes the provided command.
 * @command: The command to be executed.
 * Description: Forks a new process to execute
 * the command using execve.
 * Return: Status of the execution
 */
void execute_command(char **command)
{
	pid_t pid;
	int status;
	char **args;

	if (command == NULL)
	{
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		args = malloc(2 * sizeof(char *));
		if (args == NULL)
		{
			perror("./shell: allocation error");
			exit(EXIT_FAILURE);
		}
		args[0] = command [0];
		args[1] = NULL;

		if (execve(args[0], command, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		free(args);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("./shell");
	}
	else
	{
		/* Parent process */
		wait(&status);
	}
}
