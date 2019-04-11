#include "simple_shell.h"

/**
 *split - splits a string according to the delimiter
 *@str: pointer to the string
 *@delim: pointer to the delimiter
 *Return: an array with each word
 */

char **split(char *str, const char *delim)
{
	char **argv, *buffer, *tmpCpy = strdup(str);
	unsigned int wNum = 0, i = 0;

	/*Count the number of words to allocate memory*/
	buffer = _strtok(tmpCpy, delim);
	wNum += 1;
	while (buffer != NULL)
	{
		buffer = _strtok(NULL, delim);
		if (buffer != NULL)
			wNum += 1;
	}
	free(tmpCpy);

	/*Allocate memory and check if it couldn't*/
	argv = malloc(sizeof(char *) * (wNum + 1));
	if (argv == NULL)
		return (NULL);

	/*Save pointer in the bidimensional array*/
	buffer = _strtok(str, delim);
	if (buffer != NULL)
		*(argv) = buffer;
	else
		return (NULL);

	for (i = 1; i < wNum; i++)
	{
		*(argv + i) = _strtok(NULL, delim);
	}
	*(argv + i) = NULL;
	return (argv);
}

/**
 *_strncmp - compares two strings (first n bytes).
 *@s1: string one
 *@s2: string two
 *@n: bytes to compare
 *Return: int if zero s1 = s2, if neg s1 < s2 and if pos s2 < s1
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i1 = 0;
	int i2 = 0;
	int c = 0;

	if (n == 0)
	{
		while (c == 0 && (*(s1 + i1) || *(s2 + i2)))
		{
			c = *(s1 + i1) - *(s2 + i2);
			i1++;
			i2++;
		}
		return (c);
	}
	else
	{
		while (c == 0 && (*(s1 + i1) || *(s2 + i2)) && i1 < n && i2 < n)
		{
			c = *(s1 + i1) - *(s2 + i2);
			i1++;
			i2++;
		}
		return (c);
	}
}

/**
 *str_concat - concatenates two strings.
 *@s1: string number 1
 *@s2: string number 2
 *Return: point to a newly allocated space
 */

char *str_concat(char *s1, char *s2)
{
	int size = 0;
	int tmp = 0;
	char *strcat;
	char *aux = "";

	if (s1 == NULL)
		s1 = aux;
	if (s2 == NULL)
		s2 = aux;

	while (*(s1 + size))
		size++;
	tmp = size;
	size = 0;
	while (*(s2 + size))
		size++;
	size += tmp + 1;

	strcat = malloc(size * sizeof(char));
	if (strcat == NULL)
	{
		free(strcat);
		return (NULL);
	}

	for (; size >= tmp; size--)
		*(strcat + size) = *(s2 + size - tmp);
	for (; size >= 0; size--)
		*(strcat + size) = *(s1 + size);
	return (strcat);
}
