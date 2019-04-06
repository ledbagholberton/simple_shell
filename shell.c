#include "simple_shell.h"

/**
 *invoke_shell - Super simple shell
 *Return: 0
 */

void invoke_shell(char *name)
{
	ssize_t numLines = 0;
	size_t len = 0;
	int lenPrompt = 8;
	char *buffer = NULL, **argv, *prompt = "shelly$ ";
	pid_t child_pid;

	/*checks for interactive mode*/
	check_interactive(&lenPrompt);
	/*while no input is digited in the terminal wait*/
	write(STDOUT_FILENO, prompt, lenPrompt);
	while ((numLines = getline(&buffer, &len, stdin)) != -1)
	{
		/*split string digited to execute commands*/
		argv = split(buffer, " \n");
		/*create child for executing binary file*/
		child_pid = fork();
		if (child_pid == -1)
			perror(name);
		if (child_pid == 0)
		{
			/*validate and execute command*/
			valid_command(argv, name);
		}
		else
		{
			/*wait for child to finish*/
			wait(NULL);
		}
		write(STDOUT_FILENO, prompt, lenPrompt);
	}
	free(buffer);
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
