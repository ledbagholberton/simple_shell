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
	buffer = strtok(tmpCpy, delim);
	wNum += 1;
	while (buffer != NULL)
	{
		buffer = strtok(NULL, delim);
		if (buffer != NULL)
			wNum += 1;
	}
	free(tmpCpy);

	/*Allocate memory and check if it couldn't*/
	argv = malloc(sizeof(char *) * (wNum + 1));
	if (argv == NULL)
		return (NULL);

	/*Save pointer in the bidimensional array*/
	buffer = strtok(str, delim);
	if (buffer != NULL)
		*(argv) = buffer;
	else
		return (NULL);

	for (i = 1; i < wNum; i++)
	{
		*(argv + i) = strtok(NULL, delim);
	}
	*(argv + i) = NULL;
	return (argv);
}

/**
 *_strcmp - compares two strings.
 *@s1: string one
 *@s2: string two
 *Return: int if zero s1 = s2, if neg s1 < s2 and if pos s2 < s1
 */

int _strcmp(char *s1, char *s2)
{
	int i1 = 0;
	int i2 = 0;
	int c = 0;

	while (c == 0 && (*(s1 + i1) || *(s2 + i2)))
	{
		c = *(s1 + i1) - *(s2 + i2);
		i1++;
		i2++;
	}
	return (c);
}
