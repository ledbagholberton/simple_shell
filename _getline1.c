#include "simple_shell.h"
#include <unistd.h>

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
	ssize_t pos, size;
	char key_buff[1], my_char;

	pos = 0;
	size = *n;
	(void)stream;
	*lineptr = malloc (sizeof(char) * size);
	my_char = ' ';
	while (read(STDIN_FILENO, key_buff, sizeof(key_buff)) > 0)
	{
		my_char = key_buff[0];
		if (my_char == '\n' || my_char == 0x4)
		{
			(*lineptr)[pos] = '\n';
			return (pos);
		}
		else
		{
			(*lineptr)[pos] = my_char;
			pos++;
			if (pos > size)
			{
			size++;
			*lineptr = (char *) _realloc(*lineptr, size);
			if (*lineptr == NULL)
				return (-1);
			}
		}
	}
return(-1);
}
