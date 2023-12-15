#include "main.h"
/**
 * get_env - the string array dummy of the environment
 * @comdat: Struct containing potential args
 *
 * Return: Always 0
 */
char **get_env(com_d *comdat)
{
	if (!comdat->environ || comdat->env_changed)
	{
		comdat->environ = list_to_strings(comdat->env);
		comdat->env_changed = 0;
	}

	return (comdat->environ);
}

/**
 * _unsetenv - this removes an env variable
 * @comdat: Struct containing potential arg 
 * @var: the string env variable
 *
 * Return: 1 on delete, 0 otherwise
 */
int _unsetenv(com_d comdat, char *var)
{
	list_h *node = comdat->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			comdat->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = comdat->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (comdat->env_changed);
}

/**
 * _setenv - this Initializes a new envn variable,
 *             or mod an existing one
 * @comdat: Struct containing args
 * @var: the string env variable
 * @val: the string env variable value
 *
 *  Return: Always 0
 */
int _setenv(com_d *comdat, char *var, char *val)
{
	char *buff = NULL;
	list_h *node;
	char *p;

	if (!var || !val)
		return (0);

	buff = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, val);
	node = comdat->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buff;
			comdat->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(comdat->env), buff, 0);
	free(buff);
	comdat->env_changed = 1;
	return (0);
}
