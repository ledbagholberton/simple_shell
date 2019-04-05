#include "simple_shell.h"

/**
 *main - Super simple shell
 *Return: 0
 */

int main(void)
{
	ssize_t numLines = 0;
	size_t len = 0;
	char *buffer = NULL, **argv;
	pid_t child_pid;

	/*while no input is digited in the terminal wait*/
	printf("$ ");
	while ((numLines = getline(&buffer, &len, stdin)) != -1)
	{
		printf("$ ");
		/*split string digited to execute commands*/
		argv = split(buffer, " \n");
		/*create child for executing binary file*/
		child_pid = fork();
		if (child_pid == -1)
			perror("Error");
		if (child_pid == 0)
		{
			/*execute command*/
			if (execve(*argv, argv, NULL) == -1)
				perror("Error");
		}
		else
		{
			/*wait for child to finish*/
			wait(NULL);
		}
	}
	free(buffer);
	return (0);
}
