#include "simple_shell.h"
#include <errno.h>

/**
 *invoke_shell - Super simple shell
 *@name: name of the executable
 *Return: 0
 */

void invoke_shell(char *name)
{
	ssize_t numLines = 0;
	size_t len = 0;
	int lenPrompt = 22, wstatus;
	char *buffer = NULL, **argv, *prompt = "\033[1m\x1B[34mShelley\x1B[0m$ ";
	pid_t child_pid;

	check_interactive(&lenPrompt);
	write(STDOUT_FILENO, prompt, lenPrompt);
	while ((numLines = _getline(&buffer, &len, stdin)) != -1)
	{
		argv = split(buffer, " \n");
		child_pid = fork();
		if (child_pid == -1)
			perror(name);
		if (child_pid == 0)
			valid_command(argv, name);
		else
		{
			wait(&wstatus);
			if (WIFEXITED(wstatus) == 1)
			{
				wstatus = WEXITSTATUS(wstatus);
				if (wstatus != 0 &&  wstatus != 1)
				{
					free(buffer);
					free(argv);
					exit(wstatus);
				}
			}
		}
		write(STDOUT_FILENO, prompt, lenPrompt);
		free(buffer);
		free(argv);
		buffer = NULL;
	}
}

/**
 *check_interactive - checks if the shell is interactive or not
 *@lenPrompt: pointer to the value to be printed in terminal as prompt
 *Return: none
 */

void check_interactive(int *lenPrompt)
{
	if (isatty(STDIN_FILENO) == 0)
	{
		*lenPrompt = 0;
	}
}
