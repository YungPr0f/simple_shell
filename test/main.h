#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <time.h>
#include <stdbool.h>

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/**
 * _putchar - Don't delete _putchar, its used for testing
 * @c: character to be printed
 *
 * Description: It doesn't affect compilation or checker testing but will crash
 * the ALX tool tester if removed.
 * Return: 0 (Success) or 1 (Failure).
 */
int _putchar(char c);
int _strcmp(char *str1, char *str2);
int _strcpy(char **str1, char *str2, unsigned int s);
void _strcln(char **str);
void shell(char **env, char **av);
char *to_exe(char *cmd);
void _realloc(char ***cmd_a, size_t *n);
void _exec(char *cmd, char *temp, char **cmd_a, size_t n, int c, char **env);
void builtin_env(char **env);


void execute(char *cmde, char **cmd); 
int checks(char **cmd, char *buf);
void prompt(void);
void signal_handle( int n);
char **tokens(char *line);
char *test_path(char **path, char *cmd);
char *append_path(char *path, char *cmd);
int handle_builtin(char **cmd, char *line);
void exit_cmd(char **cmd, char *line);
void print_env(void);
int _strlen(char *str);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
char *_strchr(char *str, char c);
char *find_path(void);
void free_buffers(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif
