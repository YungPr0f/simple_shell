#include "main.h"

/**
 * _realloc - Checks the path if a command exists
 * @cmd_a: String array pointer
 * @n: String array size
 *
 * Description: Increases the allocated memory for the string array.
 * Return: 1 if a match is found and 0 otherwise.
 */
void _realloc(char ***cmd_a, size_t *n)
{
	free(*cmd_a);
	*n *= 2;
	(*cmd_a) = malloc(sizeof(char *) * *n);
}

/**
 * builtin_env - Checks the path if a command exists
 * @env: Environment variable
 *
 * Description: Prints the contents of the environment variable.
 * Return: void (Nothing)
 */
void builtin_env(char **env)
{
	int i = 0, j = 0;

	while (env[i])
	{
		j = 0;
		while (env[i][j])
			j++;

		write(1, env[i], j);
		write(1, "\n", 1);
		i++;
	}
}

/**
 * _exec - Executes a command
 * @cmd: Just a character pointer
 * @temp: Just a character pointer
 * @cmd_a: Just a character double pointer
 * @env: Environment variable
 * @n: Just and int
 * @c: Just and int
 *
 * Description: Prints the contents of the environment variable.
 * Return: void (Nothing)
 */
void _exec(char *cmd, char *temp, char **cmd_a, size_t n, int c, char **env)
{
	int i = 0, chid;

	temp = strtok(cmd, " ");
	while (temp)
	{
		if (i >= (int) n)
			_realloc(&cmd_a, &n);

		cmd_a[i] = temp;
		i++;
		temp = strtok(NULL, " ");
	}

	if (access(cmd_a[0], X_OK) == 0)
	{
		chid = fork();

		if (chid == 0)
		{
			c = execve(cmd_a[0], cmd_a, env);

			if (c == -1)
				write(1, "Execution failure\n", 17);
		}
		else
			wait(&chid);
	}
	else
		write(2, "No such executable found\n", 25);
}

