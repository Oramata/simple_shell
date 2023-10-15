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
void init_shell(void);
void shell_loop(void);
char *read_input(void);
void execute_command(char **command);


#endif
