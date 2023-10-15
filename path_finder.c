#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * find_command - Searches for the executable file in PATH directories.
 * @command: The command to look for.
 *
 * Return: The full path of the executable file if found, NULL otherwise.
 */
char *find_command(char *command)
{
	char *PATH = getenv("PATH");
	char *path, *dirs, *full_path;
	struct stat st;

	dirs = strdup(PATH);
	path = strtok(dirs, ":");
	while (path != NULL)
	{
		full_path = malloc(strlen(path) + strlen(command) + 2);
		strcpy(full_path, path);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(dirs);
			return (full_path);
		}
		free(full_path);
		path = strtok(NULL, ":");
	}
	free(dirs);
	return (NULL);
}
