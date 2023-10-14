#include "shell.h"

/**
 * display_prompt - Displays the shell prompt to the user.
 * Description: Prints the shell prompt and flushes the output buffer.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}
