#include "simple_shell.h"

int prueba(char** cadena)
{
	int iter;

	for (iter = 0; cadena[iter] != NULL; iter++)
	{
		printf("Cadena [%d] es %s \n", iter, cadena[iter]);
	}
	return (0);
}
