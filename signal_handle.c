#include "main.h"

/**
 * signal_handle - keeps track in interactive mode
 * @n: the signal number
 */
void signal_handle(int n)
{
	(void)n;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
