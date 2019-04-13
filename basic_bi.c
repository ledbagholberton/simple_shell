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
	char *home, buf[BUFSIZ], *cp, *chr;

	cp = getcwd(buf, sizeof(buf));
	home = get_home();
	chr = argv[1];
	if (argv[1] == NULL || chr[0] == '~' || chr[0] == '-')
	{
		if (chdir(home) == -1)
		{
			chdir(cp);
			perror(name);
		}
	}
	if (chdir(argv[1]) == -1)
	{
		chdir(cp);
		perror(name);
	}
}

/**
 *built_history - builtin history
 *
 *@cadena: data info
 *
 *Return: No return
 */

int built_history(char **cadena)
{
	char *home, *tmp[] = {"/bin/cat", NULL, NULL};

	(void)cadena;
	home = get_home();
	tmp[1] = str_concat(home, "/cmd_hist.txt");
	if (execve("/bin/cat", tmp, NULL) == -1)
		{
			perror("");
			free(tmp[1]);
			return (-1);
		}
	free(tmp[1]);
	return (0);
}
