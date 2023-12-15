#include "main.h"

/**
 * _eputs - input string printed
 * @s: the strings to print
 *
 * Return: Nothing
 */
void _eputs(char *s)
{
	int j = 0;
	if (!s)
		return;
	while (s[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}

}

/**
 * _eputchar - the char c written to stderr
 * @y: The char to print
 *
 * Return: 1 on success
 */
int _eputchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (y == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		j = 0;
	}
	if (y != BUF_FLUSH)
		buf(j++) = y;
	return (1);
}

/**
 * _putfd - the char y is written to given fd
 * @y: the char to print
 * @fdes: the file descriptor
 *
 * Return: 1 on succes
 */
int _putfd(char y, int fdes)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (y == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fdes, buf, j);
		j = 0;
	}
	if (y != BUF_FLUSH)
		buf[j++] = y;
	return (1);
}

/**
 * _putsfd - input string is printd
 * @s: string to print
 * @fdes: destination fd to write to
 *
 * Return: the num of char put
 */
int _putsfd(char *s, int fdes)
{
	int j = 0;
	
	if (!s)
		return (0);
	while (*s)
		j+= _putfd(*str++, fdes);
	return (i);
}
