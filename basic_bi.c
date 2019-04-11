#include "simple_shell.h"
/**
 *built_exit - exit from shell
 *
 *@status: exit status
 *
 *Return: pointer to string
 */

int built_exit(char** cadena)
{
        int status;
       	if (cadena[1] == NULL)
		kill(-1, SIGKILL);
	else
	{
		status = _atoi(cadena[1]);
		exit(status);
	}
/* In the shell program it is required to evaluate in
 * loop the parameter
 * The exit() function causes normal process termination and the value of status 
 * & 0377 is returned to the parent (see wait(2)).
 */
	return (0);
}
