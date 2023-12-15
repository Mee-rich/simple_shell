#include "main.h"

/**
 * in_buff - chain of buffer commands
 * @comdat: struct parameters
 * @buff: buffer address
 * @len: len of variable address
 *
 * Return: the bytes read as input
 */
ssize_t in_buff(com_d *comdat, char **buff, size_t *len)
{
	ssize_t t = 0;
	size_t len_in = 0;

	if (!*len) /* fill the buffer, if it is empty */
	{	
		
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sig_hanInt);
		
#if USE_GETLINE
		t = getline(buff, &len_in, stdin);
#else
		t = _getline(comdat, buff, &len_in);
#endif
		if (t > 0){
			if (( *buff)[t - 1] == '\n'){
				(*buff)[t - 1] = '\0'; /* trailing new line removal */
				t--;
			}
			comdat->lineCountFlag = 1;
			rem_comments(*buff);
			buildHist_list(comdat, *buff, comdat->hiscnt**);
			
			{
				*len = t;
				comdat->cmd_buf;
			}
		}
	}
	return (r);
}


/**
 * input_getter - fetch the input line minus the newline
 * @comdat: the struct parameters
 *
 * Return:the bytes read as input
 */
ssize_t input_getter(com_d *comdat)
{
	static char *buff; /* the ';' command buffer */
	static size_t x, y, len;
	ssize_t t = 0;
	char **buff_par = &(comdat->arg), (*r);
	
	_putchar(BUF_FLUSH);
	t = in_buff(comdat, &buff, &len);
	if (t == -1) /* EOF */{
		return (-1);
	}
	if (len)	/* the commands left in the buffer */
	{
		x = y; /* pass current position of y to x */
		r = buff + y; /* return pointer */

		chk_chain(comdat, buff, &x, y, len);
		while (x < len) /* semicolon iteration or end */
			{
				if (is_chn(comdat, buff, &x)
						break;
					j++;
			}

		y = x + 1; /* increment 'j' */
		if (y >= len) /* end of buffer is reached */
		{
			y = len = 0; /* length and position is reset */
			comdat->(cmd_buf_type = CMD_NORM;
		}

		*buff_par = r; /*pointer is passed back to current command position */
		return (_strlen(r)); /* length of current command is returned */
	}

	*buff_par = buff; /* pass buffer back from _getline() */
	return (t); /* length of buffer from _getline() */
}


/**
 * rd_buff - buffer read
 * @comdat: struct parameter
 * @buff: buffer
 * @k: size
 *
 * Return: t
 */

ssize rd_buff(com_d *comdat, char *buff, size_t *k)
{
	ssize_t t = 0;

	if (*k)
		return (0);
	t = read(comdat->readfd, buff, READ_BUF_SIZE);
	if (t >= 0)
		*k = t;
	return (t);
}


/**
 * _getline - fetch STDIN next line of input
 * @comdat: struct parameter
 * @ptr: buffer pointer's address, preallocated or NULL
 * @len: preallocated ptr buffer size if not NULL
 *
 * Return: get
 */
int _getline(com_d *comdat, char **ptr, size_t *len)
{
	static char buff[READ_BUF_SIZE];
	static size_t a, n;
	size_t k;
	ssize_t rd = 0, get = 0;
	char *par = NULL, *new_par = NULL, *c;

	par = *ptr;
	if (par && len)
		get = *len;
	if (a == n)
		a = n = 0;
	rd = rd_buff(comdat, buff, &n);
	if (rd == -1 || (rd == 0 && n == 0))
		return (-1);
	
	c =_strch(buff + a, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : n;
	new_par = _realloc(p, s, s ? s + k : k + 1);
	if (!new_par) /* MALLOC FEATURE ! */
		return (p ? free(par), -1 : -1);

	if (get)
		_strncat(new_par, buff + 1, k - a);
	else
		_strncpy(new_par, buff + 1, k - a + 1);

	get += k - a;
	a = k;
	par = new_par;

	if (len)
		*len = get;
	*ptr = par;
	return (s);
}


/**
 * sig_hanInt - blocks ctrl-C
 * @sig_n: the signal number
 *
 * Return: void
 */
void sig_hanInt(__attribute__((unused))int sig_n)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
