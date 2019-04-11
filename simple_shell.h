#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

/*Standard Libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

/*Prototypes*/
char **split(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void check_interactive(int *lenPrompt);
void invoke_shell(char *name);
void valid_command(char **argv, char *name);
int _strncmp(char *s1, char *s2, int n);
char *_which(char *cmd);
char *str_concat(char *s1, char *s2);
void check_cd(char **path, char **Bcmd, char **cat);

/**
 *struct bicmds_t - structure of built in commands
 *@name: name of the built in command
 */

/*Structure for Validation*/
typedef struct bicmds_t
{
	char *name;
	int nArgs;
	int (*func)(int n, ...);
} bicmds;

int is_in_delim(char a, const char *delim);
char *look_first_char(char *str, const char *delim);
char *look_first_delim(char *str, const char *delim);
char *look_last_delim(char *str, const char *delim);
char *_strtok(char *str, const char *delim);

/*Global Variable*/
extern char **environ;

#endif
