#include "simple_shell.h"
/**
 *_getline - Super simple shell
 *@lineptr: pointer to buffer
 *@n: size of buffer
 *@stream: kind of stream to get info
 *Return: 0
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t pos, size;
	char *key_buff[1], my_char;

	pos = 0;
	size = *n;
	*stream = *stream;
	*lineptr = malloc (sizeof(char) * size);
	while (my_char != 3)
	{
		my_char = read(0, key_buff, 1);
		if (my_char == '\n' || my_char == EOF)
		{
			*lineptr[pos] = '\0';
			return (pos);
		}
		else
		{
			*lineptr[pos] = my_char;
			pos++;
			if (pos >= size)
			{
			size++;
			*lineptr = (char *) realloc(*lineptr, size);
			if (*lineptr == NULL)
				return (-1);
			}
		}
	}
	return (pos);
}
