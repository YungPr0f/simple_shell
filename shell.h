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

#endif /* SHELL_H */
