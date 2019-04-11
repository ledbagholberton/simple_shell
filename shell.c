#include "simple_shell.h"

/**
 *invoke_shell - Super simple shell
 *@name: name of the executable
 *Return: 0
 */

void invoke_shell(char *name)
{
	ssize_t numLines = 0;
	size_t len = 0;
	int lenPrompt = 22;
	char *buffer = NULL, **argv, *prompt = "\033[1m\x1B[34mShelley\x1B[0m$ ";
	pid_t child_pid;

	/*checks for interactive mode*/
	check_interactive(&lenPrompt);
	/*while no input is digited in the terminal wait*/
	write(STDOUT_FILENO, prompt, lenPrompt);
	while ((numLines = _getline(&buffer, &len, stdin)) != -1)
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
