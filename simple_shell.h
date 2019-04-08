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

/*Prototypes*/
char **split(char *str, const char *delim);
void check_interactive(int *lenPrompt);
void invoke_shell(char *name);
void valid_command(char **argv, char *name);
int _strncmp(char *s1, char *s2, int n);
char *_which(char *cmd);
char *str_concat(char *s1, char *s2);

/**
 *struct bicmds_t - structure of built in commands
 *@name: name of the built in command
 */

/*Structure for Validation*/
typedef struct bicmds_t
{
	char *name;
	/*pointer to a function*/
} bicmds;

/*Global Variable*/
extern char **environ;
#endif
