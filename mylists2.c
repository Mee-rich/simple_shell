#include "main.h"

/**
 * list_len - the length of a linked list
 * @hh: points to first node
 *
 * Return: size of list
 */
size_t list_len(const list_h *hh)
{
	size_t i = 0;

	while (hh)
	{
		hh = hh->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings -  an array of strings of the list->str returned
 * @head: points to first node
 *
 * Return: strings array
 */
char **list_to_strings(list_h *head)
{
	list_h *node = head;
	size_t i = list_len(head), j;
	char **strrs;
	char *str;

	if (!head || !i)
		return (NULL);
	strrs = malloc(sizeof(char *) * (i + 1));
	if (!strrs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strrs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strrs[i] = str;
	}
	strrs[i] = NULL;
	return (strrs);
}


/**
 * print_list - all elements of a list_t linked list printed
 * @hh: points to first node
 *
 * Return: list size
 */
size_t print_list(const list_h *hh)
{
	size_t j = 0;

	while (hh)
	{
		_puts(convert_number(hh->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hh->str ? hh->str : "(nil)");
		_puts("\n");
		hh = hh->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - nodes that start with prefix
 * @node: points list head
 * @pref: match strings
 * @x: next character after prefix to match
 *
 * Return: node match or null
 */
list_h *node_starts_with(list_h *node, char *pref, char x)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, pref);
		if (p && ((x == -1) || (*p == x)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - the index of a node is fetched
 * @head: points to list head
 * @node: points to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_h *head, list_h *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
