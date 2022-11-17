#include "main.h"

/**
* tokens - creates tokens from given input
* @line: to be tokenized
* Return: array of strings
*/
char **tokens(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokenz = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokenz = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokenz[index] = _strdup(token);
		if (tokenz[index] == NULL)
		{
			free(tokenz);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokenz[index] = '\0';
	free(buf);
	return (tokenz);
}
