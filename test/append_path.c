#include "main.h"

/**
 * append_path - adds path
 * @path: path
 * @cmd: command entered
 * Return: buffer containing command
 */
char *append_path(char *path, char *cmd)
{
	char *buf;
	size_t i = 0, j = 0;

	if (cmd == 0)
		cmd = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}
	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (cmd[j])
	{
		buf[i + j] = cmd[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
