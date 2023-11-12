#ifndef SHELL_H
#define SHELL_H

#define MAX_ARG 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void display_prompt(void);
char *read_input(void);
char **parse_input(char *line);
char **parse_commands(char *line);
char ***parse_semicolon_separated_commands(char *line);
void init_shell(void);
void shell_loop(void);
char *find_command(char *command);
void execute_cmd(char **command);
void shell_loop(void);
void change_directory(char **args);
int parse_input_to_commands_and_operators(char *line, char ***commands, char ***operators, int *command_count);
void execute_command_sequence(char **commands, char **operators, int command_count);
int execute_command(char **command);
int execute_individual_command(char *cmd, char **args);
int execute_command(char **command);
char *find_command(char *command);
int execute_command(char **args);

#endif
