#include "main.h"

/**
 * find_path - finds the path from global environment
 * Return: NULL
 */
char *find_path(void)
{
	int a;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && a < 5)
			{
				path++;
				a++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
