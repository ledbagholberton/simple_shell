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
	return(ptr);
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
	cont = cont - 2;
	while (cont > 0)
	{
		ptr++;
		cont--;
	}
	return(ptr);
}

/**
 *rel_string - release string pointed by str & finished in ptr
 *
 *@str: pointer to string
 *@ptr: pointer to last char in string
 *
 *Return: pointer to token & str pointed to rest of string
 */
char *rel_string(char *str, char *ptr)
{
	char *new;
	int cont = 0;

	new = (char *) malloc(sizeof(char) * (ptr - str + 1));
	while (str != ptr)
	{
		new[cont] = str[cont];
		cont++;
		str++;
	}
	new[cont] = '\0';
return(new);
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
	char a, *aux2, *aux, *ptr;
	int cont = 0, flag_is = 1;
/* apunta al primer caracter encontrado diferente a delim */
	if (str != NULL)
	{
	while (flag_is == 1)
		{
		a = str[cont];
		flag_is = is_in_delim(a, delim);
		cont++;
		}
	aux = &(str[cont]);
/* apunta al ultimo caracter antes de un delim*/
	flag_is = 0;
	cont = 0;
	while (flag_is == 0)
	{
		a = aux[cont];
		flag_is = is_in_delim(a, delim);
		cont++;
	}
	aux2 = &(aux[cont]);
/* libera cadena y entrega apuntador a la cadena liberada
 * y a str apuntando a la cadena restante o al NULL
*/
	ptr = rel_string(aux, aux2);
	}
	return(ptr);
}
