#include "shell.h"

/**
 * execute_individual_command - Executes an individual command.
 * @cmd: The command with full path to be executed.
 * @args: The arguments for the command to be executed.
 * Return: The exit status of the command or -1 if an error occurred.
 */
int execute_individual_command(char *cmd, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		/* Child process attempts to execute the command. */
		if (execve(cmd, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process waits for the child's completion. */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}
	return (-1);
}

/**
 * execute_command - Processes the command with logic for '&&' and '||'.
 * @args: Parsed command line arguments including logical operators.
 */
int execute_command(char **args)
{
	int last_status = 0;
	int execute_next = 1;
	int i = 0;
	char *command_path;

	while (args[i] != NULL)
	{
		if (strcmp(args[i], "&&") == 0)
		{
			if (last_status != 0)
				execute_next = 0;
		}
		else if (strcmp(args[i], "||") == 0)
		{
			if (last_status == 0)
				execute_next = 0;
		}
		else if (execute_next)
		{
			command_path = find_command(args[i]);
			if (command_path == NULL)
			{
				fprintf(stderr, "%s: command not found\n", args[i]);
				last_status = 127;
			}
			else
			{
				last_status = execute_individual_command(command_path, &args[i]);
				free(command_path);
			}
			execute_next = 1;
		}

		if (args[i + 1] == NULL || strcmp(args[i + 1], "&&") == 0 || strcmp(args[i + 1], "||") == 0)
			execute_next = 1;

		i++;
	}
	return(your_return_value);
}
