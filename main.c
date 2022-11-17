#include "main.h"

/**
 * main - runs shell commands
 * @ac: int number of variables
 * @av: Two dimensional array of command line arguments
 * @env: Enviroment variable.
 *
 * Description: Behaves just like a shell.
 * Return: 0 for success or anything else otherwise.
 */
int main(int ac, char **av, char **env)
{
	if (ac < 2)
		shell(env, NULL);
	else
		shell(env, av);

	return (EXIT_SUCCESS);
}

