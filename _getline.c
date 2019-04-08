#include "simple_shell.h"
#include <unistd.h>

/**
 * _strcopy - copy memory
 * @str: the origin string
 * @ptr: the recipe string
 *
 * Return: No return
 */

void _strcopy(char *str, char *ptr)
{
        unsigned int cont = 0;

	while (str[cont] != 4 && str[cont] != '\n')
	{
		ptr[cont] = str[cont];
		cont++;
	}
}

/**
* _realloc - reallocate memory
* @ptr: the address of memory of old_size
* @new_size: the new size
*
* Return: Pointer to new size
*/

void *_realloc(void *ptr, unsigned int new_size)
{
	char *a;
	unsigned int cont = 0; 

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	a = malloc(new_size);
	if (a == NULL)
		return (NULL);
	while (((char *)ptr)[cont] != '\0')
	{
		a[cont] = ((char *)ptr)[cont];
		cont++;
	}
	free(ptr);
	return (a);
}

/**
 *_getline -Replcement getfile funtion
 *@lineptr: pointer to buffer
 *@n: quantity of bytes to read
 *@stream: kind of stream to get info
 *Return: number of chars read | -1 in error
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t size;
	char key_buff[1024];
	int leido;

	size = *n;
	(void)stream;
	leido = read(STDIN_FILENO, key_buff, 1024);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(sizeof(char) * 1024);
		if (*lineptr == NULL)
			return (-1);
	}
	if (leido > size)
	{
		*lineptr = (char *) _realloc(*lineptr, leido + 120);
		if (*lineptr == NULL)
			return (-1);
	}
	_strcopy(key_buff, *lineptr);
	(*lineptr)[leido - 1] = '\0';
	return(leido);
}
