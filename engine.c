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
		{"cd", prueba},
		{"env", _env},
		{"setenv", prueba},
		{"unsetenv", prueba},
		{"exit", built_exit},
		{"alias", prueba},
		{"help", prueba},
		{"history", prueba},
		{NULL, NULL}
	};
	int iter = 0;

	while (builtinCmds[iter].name != NULL)
	{
		if (_strncmp(builtinCmds[iter].name, argv[0], 0) == 0)
		{
			if (builtinCmds[iter].f(argv) == -1)
				exit(EXIT_FAILURE);
		}
		iter++;
	}
	if (execve(_which(*argv), argv, NULL) == -1)
		perror(name);
	exit(EXIT_FAILURE);
}

/**
 *_which - find the path for a command
 *@cmd: command to find
 *Return: the ful path concatenated with the command
 */

char *_which(char *cmd)
{

	struct stat st;
	unsigned int i = 0;
	char *path, *cat, *Bcmd;

	while (_strncmp(environ[i], "PATH", 4) != 0)
		i++;
	path = _strtok(environ[i], "=");
	if (*cmd != '/')
		Bcmd = str_concat("/", cmd);
	else
		return (cmd);
	path = _strtok(NULL, "");
	if (*path == ':')
		check_cd(&path, &Bcmd, &cat);
	else
		path = _strtok(path, ":");
	while (path != NULL)
	{
		path = _strtok(NULL, "");
		if (*path == ':')
		{
			check_cd(&path, &Bcmd, &cat);
		}
		else
		{
			path = _strtok(path, ":");
			cat = str_concat(path, Bcmd);
			if (stat(cat, &st) == 0)
				break;
			free(cat);
		}
	}
	if (cat != (Bcmd + 1))
		free(Bcmd);
	/*HARCODEAR EL ERROR*/
	return (cat);
}

/**
 *check_cd - checks for current path
 *@path: current path
 *@Bcmd: slash command
 *@cat: concatenation
 *Return: none
 */

void check_cd(char **path, char **Bcmd, char **cat)
{
	struct stat st;

	*cat = *Bcmd + 1;
	if (stat(*cat, &st) == 0)
		*path = NULL;
	else
		*path = _strtok(*path, ":");

}
