#include "main.h"

/**
 * exit_cmd - exit command
 * @cmd: token command
 * @line: input read from stdin
 */
void exit_cmd(char ** cmd, char *line)
{
	free(line);
	free_buffers(cmd);
	exit(0);
}
