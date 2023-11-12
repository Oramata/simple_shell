#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * parse_line - Parses a line of input into an array of arguments
 * @line: The line to parse
 * Return: An array of arguments
 */
char **parse_input(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	/* Split input into tokens where each token is a command or an operator. */
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * parse_commands - Splits a command into arguments.
 * @command_line: The command line to parse.
 * Return: An array of arguments for the command.
 */
char **parse_commands(char *command_line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(command_line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position++] = strdup(token);

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}


/**
 * parse_semicolon_separated_commands - Splits the input into command groups separated by semicolons.
 * @line: The line to parse.
 * Return: Array of command groups, each group is an array of arguments.
 */
char ***parse_semicolon_separated_commands(char *line)
{
	int command_bufsize = 64, command_position = 0;
	char ***command_groups = malloc(command_bufsize * sizeof(char **));
	char *command_group, *rest = line;

	if (!command_groups)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while ((command_group = strtok_r(rest, ";", &rest)))
	{
		command_groups[command_position++] = parse_commands(command_group);
		if (command_position >= command_bufsize)
		{
			command_bufsize += 64;
			command_groups = realloc(command_groups, command_bufsize * sizeof(char **));
			if (!command_groups)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	command_groups[command_position] = NULL;
	return (command_groups);
}

/**
 * is_operator - Checks if a string is an operator
 * @token: The string to check
 * 
 * Return: 1 if string is an operator, 0 otherwise
 */
int is_operator(const char *token)
{
	return (strcmp(token, "&&") == 0 || strcmp(token, "||") == 0 || strcmp(token, ";") == 0);
}

/**
 * resize_buffer - Resizes a buffer to a new size
 * @buffer: A pointer to the buffer to resize
 * @current_size: The current size of the buffer
 * @new_size: The new size for the buffer
 * @size_of_type: The size of the buffer's element type
 *
 * Return: A pointer to the newly resized buffer or NULL on failure
 */
void *resize_buffer(void *buffer, int current_size, int new_size, size_t size_of_type)
{
	if (new_size > current_size)
	{
		void *new_buffer = realloc(buffer, new_size * size_of_type);
		if (!new_buffer)
		{
			fprintf(stderr, "shell: allocation error\n");
			exit(EXIT_FAILURE);
		}
		return (new_buffer);
	}
	return (buffer);
}

/**
 * parse_input_with_operators - Parses an input string into command groups
 * considering '&&', '||', and ';' as command separators
 * @line: The input string to parse
 *
 * Return: A pointer to an array of command groups
 */
char ***parse_input_with_operators(char *line)
{
	int bufsize = 64, position = 0;
	char ***command_groups = malloc(bufsize * sizeof(char **));
	char *token, *next_token;
	char *rest = line;
	char **current_group;

	if (!command_groups)
	{
		fprintf(stderr, "shell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok_r(rest, " \t\r\n\a", &rest);
	while (token != NULL)
	{
		command_groups = resize_buffer(command_groups, bufsize, position + 2, sizeof(char **));

		if (!is_operator(token))
		{
			int group_size = 64, group_position = 0;
			current_group = malloc(group_size * sizeof(char *));

			if (!current_group)
			{
				fprintf(stderr, "shell: allocation error\n");
				exit(EXIT_FAILURE);
			}

			current_group[group_position++] = strdup(token);

			/* Tokenize until next operator or end of string */
			next_token = strtok_r(NULL, " \t\r\n\a", &rest);
			while (next_token != NULL && !is_operator(next_token))
			{
				current_group = resize_buffer(current_group, group_size, group_position + 2, sizeof(char *));
				current_group[group_position++] = strdup(next_token);
				next_token = strtok_r(NULL, " \t\r\n\a", &rest);
			}

			current_group[group_position] = NULL;
			command_groups[position++] = current_group;

			token = next_token;
		}
		else
		{
			token = strtok_r(NULL, " \t\r\n\a", &rest);
		}
	}
	command_groups[position] = NULL;

	return (command_groups);
}
