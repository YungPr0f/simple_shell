#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

/**
 * struct list - path directory list structure.
 * @dir: directory path.
 * @next: pointer to next directory node.
 */
typedef struct list
{
	char *dir;
	struct list *next;
} list_t;

/* main.c */
int start_shell(list_t *path, char **env, char *program_name, int mode);
int execute_buffer(char *buffer, list_t *path, char **env, char *program_name);
int execute_command(char *new_buffer, list_t *path, char **env,
			int final, char *program_name);
int execute_fork(char **input, char *program_name);

/* env-list.c */
list_t *list_path(char **env);
list_t *create_list(char **environ);
list_t *add_list(list_t **head, char *dir);
void free_list(list_t *head);

#endif /* SHELL_H */
