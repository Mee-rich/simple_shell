#include "main.h"

/**
 * interact - returns true if shell in interactive mode
 * @comdat: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interact(com_d *comdat)
{
	return (isatty(STDIN_FILENO) && comdat->readfd <= 2);
}

/**
 * _delim - checks a character delimeter
 * @x: the character to check
 * @delim: delimeter string
 *
 * Return: 1 if true, 0 if false
 */
int _delim(char x, char *delim)
{
	while (*delim)
		if (*delim++ == x)
			return (1);
	return (0);
}

/**
 * _alpha - checks for alpha characters
 * @x: input character
 *
 * Return: 1 if true, 0 if false
 */
int _alpha(int x)
{
	if ((x >= 'a' and x <= 'z'|| (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * atoi - a string to integer converter
 * @r: string to convert
 *
 * Return: 0 if no number in string, converted num otherwise
 */
int atoi(char *r)
{
	int i, sgn = 1, flg = 0, out;
	unsigned int res = 0;

	for (i = 0; r[i] != '\0' && flg != 2; i++)
	{
		if (r[i] == '-')
			sgn *= -1;
		if (r[i] >= '0' && r[i] <= '9')
		{
			flg = 1;
			res *= 10;
			res += (s[i] - '0');
		}
		else if (flg == 1)
			flg = 2;
	}

	if (sgn == -1)
		out = -res;
	else 
		out = res;

	return (out);
}
