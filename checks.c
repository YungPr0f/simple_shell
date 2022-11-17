#include "main.h"

/**
 * checks - checks built-in function
 * @cmd: token input
 * @buf: from getline function
 * Return: 1 if cmd execute, 0 if cmd does not execute
 */
int checks(char ** cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execute(cmd[0], cmd);
		return (1);
	}
	return (0);
}
