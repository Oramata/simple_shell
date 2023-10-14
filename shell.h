#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void display_prompt(void);
char *read_input(void);
char *parse_input(char *line);
void execute_command(char *command);
void init_shell(void);
void shell_loop(void);

#endif
