#include "main.h"

/**
 **_mset - memory is filled with a constant byte
 *@p: points to memory area
 *@r: the byte to fill *p with
 *@num: the amount of bytes to be filled
 *Return: pointer to the memory area p
 */
char *_mset(char *p, char r, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		p[i] = r;
	return (p);
}

/**
 * sfree - to free a string of strings
 * @ps: the string of strs
 */
void sfree(char **ps)
{
	char **s = ps;

	if (!ps)
		return;
	while (*ps)
		free(*ps++);
	free(s);
}

/**
 * _myalloc - a block of memory is reallocated
 * @ptr: pooints to previous malloc block
 * @old_s: previous block byte size
 * @new_s: new block byte size
 *
 * Return: pointer to the old block
 */
void *_myalloc(void *ptr, unsigned int old_s, unsigned int new_s)
{
	char *p;

	if (!ptr)
		return (malloc(new_s);
	if (!new_s)
		return (free(ptr), NULL);
	if (new_s == old_s)
		return (ptr);

	p = malloc(new_s);
	if (!p)
		return (NULL);

	old_s = old_s < new_s ? old_s : new_s;
	while (old_si--)
		p[old_s] = ((char *)ptr)[old_s];
	free(ptr);
	return (p);
}
