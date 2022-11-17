#include "main.h"

/**
 * execute - executes commands entered by user
 * @cmde: command entered
 * @cmd: vector array of pointer to commands
 * Return: 0 success
 */
void execute(char *cmde, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cmde);
	if (child_pid == 0)
	{
		execve(cmde, cmd, env);
		perror(cmde);
		free(cmde);
		fre_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
