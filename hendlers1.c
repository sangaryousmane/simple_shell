#include "main.h"



/**
* _memcopy - copy some bytes from source to destination
* @d: destination
* @src: source
* @n: size
* Return void
*/
char *_memcopy(char *d, char src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		d[i] = src[i];
	}

	return (d);
}

void *_fill(void *arr, int element, unsigned int len)
{
	char *ptr = arr;
	unsigned int i = 0;

	while (i < len)
	{
		*ptr = element;
		ptr++;
		i++;
	}

	return (arr);
}

/**
* _customer_realloc - Reallocates a block of memory
* @p: the pointer
* @pre_size: old size
* @current_size: New size of the pointer
* Return: a void pointer with reallocated memory
*/
void *_customer_realloc(void *to, unsigned int pre_size, unsigned int current_size)
{
	void *r;

	if (current_size == pre_size)
	{
		return (to);
	}
	if (current_size == 0 && to)
	{
		free(to);
		return (NULL);
	}

	r = malloc(current_size);
	if (r == NULL)
	{
		return (NULL);
	}
	if (to == NULL)
	{
		_fill(r, '\0', current_size);
		free(to);
	}
	else
	{
		_memcopy(r, to, pre_size);
		free(to);
	}
	return (r);
}
