#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void init_shell(void);
void shell_loop(void);
char *read_line(void);
char **parse_line(char *line);
int execute(char **args);

#endif
