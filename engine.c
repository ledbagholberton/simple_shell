#include "simple_shell.h"

/**
 *valid_command - validates if the command is a built in or has a binary file
 *@argv: array of strings input
 *@name: name of the shell
 *Return: none
 */

void valid_command(char **argv, char *name)
{
	bicmds builtinCmds[] = {
		{"cd"},
		{"env"},
		{"setenv"},
		{"unsetenv"},
		{"exit"},
		{"alias"},
		{"help"},
		{"history"},
		{NULL}
	};
	int iter = 0;

	while (builtinCmds[iter].name != NULL)
	{
		if (_strcmp(builtinCmds[iter].name, argv[0]) == 0)
		{
			printf("LLAMAR FUNCION [%s]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		iter++;
	}
	if (execve(*argv, argv, NULL) == -1)
		perror(name);
	exit(EXIT_FAILURE);
}
