#include "simple_shell.h"

/**
 *main - Entry point
 *Return: 0
 */

int main(int argc, char *argv[])
{
	(void)argc;
	invoke_shell(argv[0]);
	return (0);
}
