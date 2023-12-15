#include "main.h"

/**
 * clr_com - initializes com_d struct
 * @comdat: struct address
 */
void clr_info(com_d *comdat)
{
	comdat->arg = NULL;
	comdat->argv = NULL;
	comdat->path = NULL;
	comdat->argc = 0;
}

/**
 * set_com - this initializes a com_d struct
 * @comdat: struct address
 * @av: argument vector
 */
void set_inf(com_d *comdat, char **av)
{
	int i = 0;

	comdat->fname = av[0];
	if (comdat->arg)
	{
		comdat->argv = strtow(comdat->arg, " \t");
		if (!comdat->argv)
		{

			comdat->argv = malloc(sizeof(char *) * 2);
			if (comdat->argv)
			{
				comdat->argv[0] = _strdup(comdat->arg);
				comdat->argv[1] = NULL;
			}
		}
		for (i = 0; comdat->argv && comdat->argv[i]; i++)
			;
		comdat->argc = i;

		replace_alias(comdat);
		replace_vars(comdat);
	}
}

/**
 * free_com - frees com_d struct fields
 * @comdat: struct address
 * @all: true if all fields are freed
 */
void free_com(com_d *comdat, int all)
{
	ffree(comdat->argv);
	comdat->argv = NULL;
	comdat->path = NULL;
	if (all)
	{
		if (!comdat->cmd_buf)
			free(comdat->arg);
		if (comdat->env)
			free_list(&(comdat->env));
		if (comdat->history)
			free_list(&(comdat->history));
		if (comdat->alias)
			free_list(&(comdat->alias));
		ffree(comdat->environ);
			comdat->environ = NULL;
		bfree((void **)comdat->cmd_buf);
		if (comdat->readfd > 2)
			close(comdat->readfd);
		_putchar(BUF_FLUSH);
	}
}
