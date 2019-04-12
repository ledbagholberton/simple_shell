#include "simple_shell.h"

/**
 *main - Entry point
 *@argc: number of arguments
 *@argv: array of strings with the arguments inside
 *Return: 0
 */

int main(int argc, char *argv[], char **env)
{
	(void)argc;
	create_env(env);
	invoke_shell(argv[0]);
	return (0);
}
