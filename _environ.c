#include "main.h"

/**
 * _myenv - the current environment is printed
 * @comdat: struct parameter args
 *
 * Return: Always 0
 */
int _myenv(com_d *comdat)
{
	prnt_list_str(comdat->env);
	return(0);
}

/**
 * _getenv - value of an environ variable is fetched
 * @comdat: struct containing input args
 * @ nam: environment variable name
 *
 * Return: Always 0
 */
char *_getenv(com_d *comdat, const char *name)
{
	list_h *node = comdat->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if ( p && *p)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - initialization of new environment var
 * 		 or modify previous ones
 * @comdat: struct containing potential args
 *
 * Return: Always 0
 */
int _mysetenv(com_d *comdat)
{
	if(comdat->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);

	}

	if (_setenv(comdat, comdat->argv[1], comdat->argv[2]))
		return (0);
	return (1);
}


/**
 * _myunsetenv - an env variables is removed
 * @comdat: struct containing potental args
 *
 * Return: Always 0
 */
int _myunsetenv(com_d *comdat)
{
	int i;

	if (comdat->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= comdat->argc; i++)
	{
		_unsetenv(comdat, comdat->argv[i]);
	}
	
	return (0);
}

/**
 * fill_envList - env linked list filled
 * @comdat: struct comtaining potential args.
 *
 * Return: Always 0
 */
int fill_env_list(com_d *comdat)
{
	list_h *node = NULL;
	size_t = j;

	for (j = 0; environ[j];  i++)
		add_node_end(&node, environ[j], 0);
	comdat->env = node;
	return (0);
}
