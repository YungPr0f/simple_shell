#include "main.h"

/**
 * handle_builtin - execution of built-in function
 * @cmd: token command
 * @line: input read in stdin
 * Return: 1 if executed, 0 fail
 */
int handle_builtin(char **cmd, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if(_strcmp(*cmd, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*cmd, builtin.exit) == 0)
	{
		exit_cmd(cmd, line);
		return (1);
	}
	return (0);
}
