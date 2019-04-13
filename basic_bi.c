#include "simple_shell.h"
/**
 *built_exit - exit from shell
 *
 *@cadena: array from argv
 *
 *Return: pointer to string
 */

int built_exit(char **cadena)
{
	int status;

	if (cadena[1] == NULL)
	{
		free(cadena[0]);
		free(cadena);
		exit(124);
	}
	else
	{
		status = _atoi(cadena[1]);
		free(cadena[0]);
		free(cadena);
		exit(status);
	}
	return (0);
}

/**
 *built_cd - change directory
 *
 *@cadena: array from argv
 *
 *Return: pointer to string
 */

int built_cd(char **cadena)
{
	free(cadena[0]);
	free(cadena);
	exit(123);
}

/**
 *cd_parent - change directory
 *
 *@argv: array from argv
 *@name: name  of shell
 *Return: pointer to string
 */

void cd_parent(char **argv, char *name)
{
	unsigned int i = 0, cont;
	char *home, buf[BUFSIZ], *cp;

	cp = getcwd(buf, sizeof(buf));
	if (argv[1] == NULL)
	{
		while (_strncmp(environ[i], "HOME", 4) != 0)
			i++;
		for (cont = 0; environ[i][cont] != '='; cont++)
			;
		home = environ[i] + cont + 1;
		if (chdir(home) == -1)
			perror(name);
	}
	else if (chdir(argv[1]) == -1)
	{
		chdir(cp);
		exit(0);
		perror("Error en CD");
	}
}
