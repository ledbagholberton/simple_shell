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
		exit(254);
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
