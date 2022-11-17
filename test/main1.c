#include "main.h"

/**
 * main - reads, executes and print
 * @ac: argument counter
 * @av: argument vector
 * @env: environment vector
 * Return: 0 success
 */
int main(int ac, char **av, char *env[])
{
	char *line =NULL, *pathcmd = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **cmd = NULL, **paths = NULL;
	(void)env, (void)av;

	if (ac < 1)
		return (-1);
	signal(SIGINT, signal_handle);
	while (1)
	{
		free_buffers(cmd);
		free_buffers(paths);
		free(pathcmd);
		prompt();
		linesize = getline(&line, &bufsize, stdin);

		if (linesize < 0)
			break;
		info.ln_count++;
		if(line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		cmd = tokens(line);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (checks(cmd, line))
			continue;
		path = find_path();
		paths = tokens(path);
		pathcmd = test_path(paths, cmd[0]);
		if (!pathcmd)
			perror(av[0]);
		else
			execute(pathcmd, cmd);
	}

	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
