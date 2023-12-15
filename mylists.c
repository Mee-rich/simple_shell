#include "main.h"

/**
 * add_node - a node is added to the start of the list
 * @head: head node address pointer
 * @str: str field of node
 * @num: history node index
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - a node is added to end of the list
 * @head: head node address pointer
 * @str: node to string field
 * @num: history node index
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_h *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_h));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_h));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - the str element of a list_t linked list is printed
 * @hh: first node pointer
 *
 * Return: size of list
 */
size_t print_list_str(const list_h *hh)
{
	size_t j = 0;

	while (hh)
	{
		_puts(hh->str ? hh->str : "(nil)");
		_puts("\n");
		hh = hh->next;
		j++;
	}
	return (j);
}

/**
 * delete_node_at_index - node at given index is deleted
 * @head: first node's pointer address
 * @index: node index to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_h *node, *prev_node;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (j == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		j++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - all nodes of a list are freed
 * @head_pter:  pointer address to head node
 *
 * Return: void
 */
void free_list(list_h **head_pter)
{
	list_h *node, *next_node, *head;

	if (!head_pter || !*head_pter)
		return;
	head = *head_pter;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_pter = NULL;
}
