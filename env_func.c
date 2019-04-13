#include "simple_shell.h"

/**
 *create_env - creates the environmentin a file named env.txt
 *@env: enviroment variable
 *Return: int status
 */

void create_env(char **env)
{
	int fileDesc, envIter = 0, len = 0;

	fileDesc = open("env.txt", O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fileDesc == -1)
		return;
	while (env[envIter] != NULL)
	{
		len = _strlen(env[envIter]);
		write(fileDesc, env[envIter], len);
		write(fileDesc, "\n", 1);
		envIter++;
	}
	close(fileDesc);
}

/**
 *_env - prints all the enviromental variables
 *@argv: array of strings
 *Return: int status
 */

int _env(char *argv[])
{
	char *cat[] = {"/bin/cat", "env.txt", NULL};

	(void) argv;
	if (execve(cat[0], cat, NULL) == -1)
		exit(-1);
	return (0);
}
