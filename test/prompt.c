#include "main.h"

/**
 * prompt - prints $; let user know program is ready for input
 * prints the prompt if the shell is in interactive mode
 */
void prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
