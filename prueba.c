#include "simple_shell.h"

/**
 *prueba - temporal function for those built in that have not been created yet
 *@cadena: command
 *Return: 0
 */

int prueba(char **cadena)
{
	int iter;

	for (iter = 0; cadena[iter] != NULL; iter++)
	{
		printf("Cadena [%d] es %s \n", iter, cadena[iter]);
	}
	return (0);
}
