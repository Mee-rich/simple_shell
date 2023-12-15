#include "main.h"

/**
 * _hist - the history list is displayed, one command per line, 
 * 		preceded with line numbers, 0 as the start.
 * @comdat: struct that conatains potential args.
 *
 * Return: Always 0
 */
int _hist(com_d *comdat)
{
	print_list(comdat ->history);
	return (0);
}

/**
 * unset_alias - alias set to string
 * @comdat: struct parameter
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(com_d *info, char *str)
{
	char *y, r;
	int res;

	y = _strchr(str, '=');
	if (!p)
		return (-1);
	r = *y;
	*y = 0;
	res = delete_node_at_index(&(comdat->alias),
			get_node_index(comdat->alias, node_starts_with(comdat->alias, str, -1)));
	*y = r;
	return (res);
}

/**
 * _setalias - alias is set to string
 * @comdat: struct parameter
 * @str: the alias string 
 *
 * Return: Always 0 on success, 1 on error
 */
int _setalias(com_d *comdat, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!p)
		return (1);
	if(!*++q)
		return (unset_alias(comdat, str));
	
	unset_alias(comdat, str);
	return (add_node_end(&(comdat->alias), str, 0) == NULL);
}

/**
 * prnt_alias - an alias of string is printed
 * @node: alias node
 *
 * Return: Always 0 on suceess, 1 on error
 */
int prnt_alias(list_h *node)
{
	char *q = NULL, *c = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (c = node->str; q <= c; c++)
			_putchar(*c);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - this is a copy of alias (man alias)
 * @comdat: struct containing args. maintains constant
 * 		 function prototype
 *
 * 		 Return: Always 0
 */
int _alias(com_d *comdat)
{
	int i = 0;
	char *q = NULL;
	list_h *node = NULL;

	if (comdat->argc == 1)
	{
		node = comdat->alias;
		while (node)
		{
			prnt_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; comdat->arfv[i]; i++)
	{
		q =_strchr(comdat->argv[i], '=');
		if (q)
			_setalias(comdat, comdat->argv[i]);
		else
			prnt_alias(node_starts_with(comdat->alias, comdat->argv[i],'='));
	}

	return (0);
}
