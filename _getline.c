#include "simple_shell.h"

/** count_delim - count until next delim
 * 
 *@delim_2: delim strings like \n, ;, &&, ||
 *Return: Integer with long
 *remind that fd_log is already open
 */

int delete_delim(char *delim_2)
{
	int fd_log, leido, escrito, cont;
	char tmp_buffer[1024];
	long int diferencia;

	for (cont = 0; cont == 1023; cont++)
		tmp_buffer[cont] = 4;
	fd_log = open ("cmd_log.txt", O_RDWR);
	leido = read(fd_log, tmp_buffer, 1024);
	close(fd_log);
	if (leido == -1 || leido == 0)
		return (-1);
	diferencia = look_first_delim(tmp_buffer, delim_2) - tmp_buffer + 1;
	fd_log = open("cmd_log.txt", O_WRONLY | O_TRUNC);
	escrito = write (fd_log, look_first_delim(tmp_buffer, delim_2) + 1, (long int)1024 - diferencia);
	if (escrito ==  -1)
		return (-1);
	close(fd_log);
	return(escrito);			
}


/**
 * _strcopy - copy memory
 * @str: the origin string
 * @ptr: the recipe string
 *
 * Return: No return
 */

int _strcopy(char *str, char *ptr)
{
        unsigned int cont = 0;

	while (str[cont] != 4 && str[cont] != '\n' && str[cont] != '\0')
	{
		ptr[cont] = str[cont];
		cont++;
	}
	return(cont);
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
	char *delim_2 = ";\n";
	int leido, escrito, del_delim = 0, fd_log, fd_hist, historico = 0;

	size = *n;
	(void)stream;

	leido = read(STDIN_FILENO, key_buff, 1024);
	fd_log = open("cmd_log.txt", O_RDWR | O_TRUNC | O_CREAT, 0660);
	fd_hist = open("cmd_hist.txt", O_RDWR | O_APPEND | O_CREAT, 0660);
	escrito = write(fd_log, key_buff, leido);
	if (escrito  == -1)
		return (-1);
	historico = write(fd_hist, key_buff, leido) + historico;
	if (historico == -1)
		return (-1);
	close (fd_hist);
	close (fd_log);

	fd_log = open("cmd_log.txt", O_RDONLY);
	leido = read(fd_log, key_buff, 1024);
	if (leido == -1)
		return (-1);

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
	leido = _strcopy(key_buff, *lineptr);
	(*lineptr)[leido] = '\0';
	del_delim = delete_delim(delim_2);
	if (del_delim == -1)
		return (-1);


	return(leido);
}
