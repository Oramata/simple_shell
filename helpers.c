#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * handle_error - Handles errors by printing an error message.
 * @error_message: The error message to be printed.
 */
void handle_error(const char *error_message)
{
	perror(error_message);
	/* More error handling logic can be added here */
}

/**
 * trim_whitespace - Trims leading and trailing whitespace from a string.
 * @str: The string to be trimmed.
 *
 * Return: A pointer to the trimmed string.
 */
char *trim_whitespace(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (*str == 0);

	char *end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	end[1] = '\0';

	return (str);
}
