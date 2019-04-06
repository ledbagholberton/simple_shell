#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

/*Standard Libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/*Prototypes*/
char **split(char *str, const char *delim);
void check_interactive(int *lenPrompt);
void invoke_shell(void);

#endif
