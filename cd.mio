/**
 *built_cd - exit from shell
 *
 *@path: new directory
 *
 *Return: Success of failure (ErrNo)
 * 0 if succcess & -1 in error / errno
 */
int built_cd(const char* path)
{

// no abre un hijo porque en ese caso 
// el directorio abierto se cerrara
// int chdir(const char* path)

	if (path == NULL)
	{
		write(STDOUT_FILENO, "No inputs", 9);
		return (-1);
	}
	if (chdir(path) != 0)
	{	
	write(STDOUT_FILENO, "No change directory", 19);
	return (-1);
	}
	return (0);
}





}
