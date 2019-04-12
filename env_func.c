#include "simple_shell.h"

/**
 *create_env - creates the environmentin a file named env.txt
 *@argv: array of strings
 *Return: int status
 */

int create_env(void)
{
	int fileDesc, numBytes, envIter = 0, parEnvIt = 0, comp = -1, len = 0;
	char *fixed_fields[] = {"USER=", "LANGUAGE=", "SESSION=",
				"COMPIZ_CONFIG_PROFILE=", "SHLVL=",
				"HOME=", "C_IS=Fun_:)", "DESKTOP_SESSION=",
				"LOGNAME=", "TERM=", "PATH=", "DISPLAY=", NULL};

	(void)numBytes;
	fileDesc = open("env.txt", O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fileDesc == -1)
		return (-1);
	while (fixed_fields[envIter] != NULL)
	{
		len = _strlen(fixed_fields[envIter]);
		for (parEnvIt == 0;;parEnvIt++)
		{
			comp = _strncmp(environ[parEnvIt],
					fixed_fields[envIter],len);
			if (comp == 0 || environ[parEnvIt] == NULL)
				break;
		}
		printf("%s\n", environ[parEnvIt]);
	}
/*	numBytes = write(fileDesc, text_content, len);
	if (numBytes == -1)
	{
		close(fileDesc);
		return (-1);
		}*/
	close(fileDesc);
}

/**
 *_env - prints all the enviromental variables
 *@argv: array of strings
 *Return: int status
 */
/*
int _env(char *argv[])
{
	unsigned int len = 0, envIt = 0, selfEnvIt = 0;

	if (argv[1] == NULL)
	{
		while 
		len = _strlen()
	}
	else
	{
		exit(2);
	}

}
*/
