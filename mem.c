#include "main.h"

/**
 * mfree - free pointer and change the 
 * 	   value of the  address to NULL
 * @p:  pointer address to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int mfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
