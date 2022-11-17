#include "main.h"

/**
* _strcmp - compares two strings
* @str1: compared to s2
* @str2: compared to s1
* Return: returns difference between strings
*/
int _strcmp(char *str1, char *str2)
{
	int i = 0, output;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;

	output = (*(str1 + i) - *(str2 + i));

	return (output);
}

/**
* _strlen - returns the length of a string
* @str: string passed
* Return: returns length of string passed
*/
int _strlen(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
* _strncmp - compares two strings up to n bytes
* @str1: compared to s2
* @str2: compared to s1
* @n: number of bytes
* Return: difference between str1 and str2
*/
int _strncmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

/**
* _strdup - dupicates string
* @str: to be duplicated
* Return: pointer to duplicate string
*/
char *_strdup(char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *str != '\0'; str++, i++)
		ptr[i] = str[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* _strchr - locates a character in a string
* @str: string to be checked
* @c: character to be located
* Return: returns pointer to first occurence of character
* or NULL if character not found
*/
char *_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (!c)
		return (str);
	return (NULL);
}
