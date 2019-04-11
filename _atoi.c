#include "simple_shell.h"

/**
 *_atoi -  convert a string to an integer
 *@s: string to be converted
 *Return: the resulted integer.
 */

int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;
	int tmp2;
	int cont = 0;
	int tmp = 1e9;

	while (*(s + i))
	{
		if (*(s + i) == '-')
			sign *= -1;
		if ((*(s + i) >= '0') && (*(s + i) <= '9'))
		{
			if (cont == 0)
			{
				cont = i;
				while (((*(s + cont) >= '0') && (*(s + cont) <= '9')))
				{
					cont++;
				}
				cont -= i;
				while (cont != 10)
				{
					tmp /= 10;
					cont++;
				}
			}
			num += ((*(s + i)) - '0') * tmp;
			tmp /= 10;
			if (tmp == 0)
				break;
		}
		i++;
	}
	tmp2 = sign * num;
	return (tmp2);
}
