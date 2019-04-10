#include "simple_shell.h"
#include <string.h>
/**
 *is_in_delim - replace strtok function
 *
 *@a: pointer to string
 *@delim: pointer to string delim
 *
 *Return: flag = 1 si char a is in delim
 */
int is_in_delim(char a, const char *delim)
{
	int flag = 0, cont;

	for (cont = 0; delim[cont] != '\0'; cont++)
	{
		if (delim[cont] == a)
			flag = 1;
	}
	return (flag);
}

/**
 *look_first_char - found first char differ delim
 *
 *@str: pointer to string
 *@delim: pointer to string delim
 *
 *Return: pointer to first char different to delim
 */
char *look_first_char(char *str, const char *delim)
{
        char a, *ptr;
        int cont = 0, flag_is = 1;

        while (flag_is == 1)
        {
                a = str[cont];
                flag_is = is_in_delim(a, delim);
                cont++;
        }
        ptr = str;
        cont--;
        while (cont > 0)
        {
                ptr++;
                cont--;
        }
        return (ptr);
}

/**
 *look_first_delim - replace strtok function
 *
 *@str: pointer to string
 *@delim: pointer to string delim
 *
 *Return: pointer to first char different to delim
 */
char *look_first_delim(char *str, const char *delim)
{
	char a, *ptr;
	int cont = 0, flag_is = 0;

	while (flag_is == 0)
	{
		a = str[cont];
		flag_is = is_in_delim(a, delim);
		cont++;
	}
	ptr = str;
	cont--;
	while (cont > 0)
	{
		ptr++;
		cont--;
	}
	return (ptr);
}

/**
 *look_last_delim - look last char bfoor replace strtok function
 *
 *@str: pointer to string with char different to dilem
 *@delim: pointer to string delim
 *
 *Return: pointer to first char different to delim
 */
char *look_last_delim(char *str, const char *delim)
{
	char a, *ptr;
	int cont = 0, flag_is = 0;

	while (flag_is == 0)
	{
		a = str[cont];
		flag_is = is_in_delim(a, delim);
		cont++;
	}
	ptr = str;
	cont = cont - 1;
	while (cont > 0)
	{
		ptr++;
		cont--;
	}
	return (ptr);
}

/**
 *rel_string - release string pointed by str & finished in ptr
 *
 *@str: pointer to string
 *@ptr: pointer to last char in string
 *@long: long string str
 *Return: pointer to token & str pointed to rest of string
 */
char *rel_string(char *str, char *ptr, int len)
{
	char *new, *aux;
	int fd_str, cont;
	long int dif;

	aux = str;
	dif = ptr - str + 1;
	new = malloc (sizeof(char) * (dif + 1));
	fd_str = open("token.txt", O_RDWR);
	read(fd_str, aux, len);
	for (cont = 0; cont <= dif; cont++)
		new[cont] = str[cont];
       	new[dif] = '\0';
	close (fd_str);
	open ("token.txt", O_RDWR | O_TRUNC);
	write(fd_str, ptr, len - dif);
	close(fd_str);
	return (new);
}

/**
 *_strtok - replace strtok function
 *
 *@str: pointer to string
 *@delim: pointer to string delim
 *
 *Return: pointer to string
 */
char *_strtok(char *str, const char *delim)
{
	char *aux2, *aux1;
	static char *ptr;

	if (str != NULL)
	{
		aux1 = look_first_char(str, delim);
		aux2 = look_last_delim(str, delim);
		if (aux2 <= aux1)
			return (NULL);
	        aux2[0]  = '\0';
		ptr = aux2 + 1;
		return(aux1);
	}
	aux1 = ptr;
	aux2 = look_last_delim(ptr, delim);
	if (aux2 <= aux1)
		return (NULL);
	aux2[0] = '\0';
	ptr = aux2 + 1;
	return(aux1);
}


int main()
{
        char message[] = "  ;Lorem; ipsum ;; dolor sit amet, adipiscing elit.";
        char* word;
	char delim[] = " ;"

        /* get the first word from the message, seperated by
         * space character */
        word = _strtok(message, " ");
        printf("1st word: %s\n", word);

        /* get the second word from the message, NULL must be
         * used to get tokens from the previous string now */
        word = _strtok(NULL, " ");
        printf("2nd word: %s\n", word);

        /* the following loop gets the rest of the words until the
         * end of the message */
        while ((word = _strtok(NULL, " ")) != NULL)
                printf("Next: %s\n", word);
        return 0;
}
