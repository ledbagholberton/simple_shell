#include "simple_shell.h"

/**
 *create_env - creates the environmentin a file named env.txt
 *@env: enviroment variable
 *Return: int status
 */

void create_env(char **env)
{
	int fileDesc, envIter = 0, parEnvIt = 0, comp = 0, len = 0;
	char *fixed_fields[] = {"USER=", "LANGUAGE=", "SESSION=",
				"COMPIZ_CONFIG_PROFILE=", "SHLVL=",
				"HOME=", "C_IS=Fun_:)", "DESKTOP_SESSION=",
				"LOGNAME=", "TERM=", "PATH=", "DISPLAY=", NULL};

	fileDesc = open("env.txt", O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fileDesc == -1)
		return;
	while (fixed_fields[envIter] != NULL)
	{
		len = _strlen(fixed_fields[envIter]) - 1;
		for (parEnvIt = 0; env[parEnvIt] != NULL; parEnvIt++)
		{
			comp = _strncmp(env[parEnvIt],
					fixed_fields[envIter], len);
			if (comp == 0)
				break;
		}
		if (env[parEnvIt] != NULL)
		{
			len = _strlen(env[parEnvIt]);
			write(fileDesc, env[parEnvIt], len);
			write(fileDesc, "\n", 1);
		}
		else
		{
			write(fileDesc, fixed_fields[envIter], len + 1);
			if (_strncmp(fixed_fields[envIter], "C_IS=Fun_:)", 0) != 0)
				write(fileDesc, "NA\n", 3);
			else
				write(fileDesc, "\n", 1);
		}
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
