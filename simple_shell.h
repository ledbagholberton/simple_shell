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
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void check_interactive(int *lenPrompt);
void invoke_shell(char *name);

int is_in_delim(char a, const char *delim);
char *look_first_delim(char *str, const char *delim);
char *look_last_delim(char *str, const char *delim);
char *rel_string(char *str, char *ptr);
char *_strtok(char *str, const char *delim);

#endif
