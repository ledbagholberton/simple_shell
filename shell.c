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
	int lenPrompt = 22, wstatus = 0, wstatus_tmp = 15;
	char *buffer = NULL, **argv;
	pid_t child_pid;

	check_interactive(&lenPrompt);
	print_prompt(lenPrompt);
	while ((numLines = _getline(&buffer, &len, stdin)) != -1)
	{
		wstatus_tmp = wstatus;
		argv = split(buffer, " \n");
		child_pid = fork();
		child_pid == -1 ? perror(name) : (void) 0;
		if (child_pid == 0)
			valid_command(argv, name);
		else
		{
			wait(&wstatus);
			hand_status(wstatus, argv, name, buffer, wstatus_tmp);
		}
		print_prompt(lenPrompt);
		free(buffer);
		free(argv);
		buffer = NULL;
	}
}

/**
 *hand status - handling exit status
 *@wstatus: pointer to the value to be printed in terminal as prompt
 *@argv: data arrays with commands
 *@name: name
 *@buffer: buffer
 *@wstatus_tmp: temporal wstatus
 *Return: none
 */
void hand_status(int wstatus, char **argv, char *name,
		 char *buffer, int wstatus_tmp)
{
	if (WIFEXITED(wstatus) == 1)
	{
		wstatus = WEXITSTATUS(wstatus);
		if (wstatus != 0 &&  wstatus != 1 && wstatus != 255)
		{
			if (wstatus == 123)
				cd_parent(argv, name);
			else
			{
				free(buffer);
				free(argv);
				if (wstatus == 124)
					exit(wstatus_tmp);
				else
					exit(wstatus);
			}
		}
	}
}

/**
 *print_prompt- print the prompt in shell
 *@lenPrompt: len of prompt
 *Return: none
 */

void print_prompt(int lenPrompt)
{
	char *cp, *my_prompt, *buf = NULL;
	char *prompt = "\033[1m\x1B[34mShelley\x1B[0m:";
	int len;

	if (lenPrompt != 0)
	{
		cp = getcwd(buf, 0);
		my_prompt = str_concat(prompt, cp);
		len = _strlen(my_prompt);
		write(STDOUT_FILENO, my_prompt, len);
		write(STDOUT_FILENO, "$ ", 2);
		free(cp);
		free(my_prompt);
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
