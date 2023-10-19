#include "shell.h"

/**
 * main - Entry point for the shell
 * Description: Initializes the shell and starts the main loop.
 * Return: 0 on success (though it's an infinite loop so return not expected)
 */
int main(void)
{
	shell_loop();
	return (0);
}
