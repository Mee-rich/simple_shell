#include "main.h"

/**
 * _erroratoi - string to integer conversion
 * @str: the string to convert
 *
 * Return: 0 if no numbers in string, converted number
 * 		otherwise -1 on error
 */
int _erroratoi(char *str)
{
	int j;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	for(j = 0; str[j] != '\0'; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_err - error message printed
 * @comdat: parameter and return comdat struct
 * @errs: str with specified error type
 *
 * Return: 0 if no number in string, converted number
 * 		 otherwise -1 on error
 */void print_err(com_d comdat char *errs)
{
	_eputs(comdat->fname);
	_eputs(": ");
	prnt_d(comdat->lineCount, STDERR_FILENO);
	_eputs(": ");
	_eputs(comdat->argv[0]);
	_eputs(": ");
	_eputs(errs);
}

/**
 * prnt_d - funct prints a decimal (integer) num (base 10)
 * @in: the input
 * @fdes: the filedescriptor to write to
 *
 * Return: number of chars printed
 */
int prnt_d(int in, int fdes)
{
	int (*__putchar)(char) = _putchar;
	int j, cnt = 0;
	unsigned int _abs_, cur;

	if (fdes == STDERR_FILENO)
		__putchar = _eputchar;
	if (in < 0)
	{
		_abs_ = -in;
		__putchar('-');
		cnt++;
	}
	else
		_abs_ = in;
	cur = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			cnt++;
		}
		cur %= j;
	}
	__putchar('0' + cur);
	cnt++;

	return (cnt);
}

/**
 * convert_num - a conversion functin, a clone of itoa
 * @num: number
 * @b: base
 * @flg: flags argument
 *
 * Return: string
 */
char *convert_num(long int num, int b, int flg)
{
	static char *arr;
	static char buff[50];
	char sgn = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flg & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sgn = '-';

	}
	arr = flg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % b];
		n /= b;
	} while (n != 0);

	if (sgn)
		*--ptr = sgn;
	return (ptr);
}

/**
 * rem_comments - this function replaces '#' with '\0'
 * @buff: address of  string to modify
 *
 * Return: Always 0;
 */
void rem_comments(char *buff)
{
	int j;

	for (j = 0; buff[j] != '\0'; j++)
		if (buff[j] == '#' && (!j || buff[j - 1] == ' '))
		{
			buff[j] = '\0';
			break;
		}
}
