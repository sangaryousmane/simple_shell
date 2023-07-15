#include "main.h"



/**
* _exit_handler - Handle the ^C shortcut
* @signal: signal to capture
* Return: nothing
*/
void _exit_handler(int signal)
{
	if (signal == 2)
	{
		DISPLAY_TO_STDOUT("\n$hsh ");
	}
}

/**
* _memcopy - copy some bytes from source to destination
* @d: destination
* @src: source
* @n: size
* Return: void
*/
char *_memcopy(char *d, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		d[i] = src[i];
	}

	return (d);
}

/**
* _fill - fill array values
* @arr: void pointer
* @element: element to fill
* @len: the length
* Return: nothing
*/
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
* _custom_realloc - Reallocates a block of memory
* @to: the void pointer
* @pre_size: old size
* @current_size: New size of the pointer
* Return: a void pointer with reallocated memory
*/
void *_custom_realloc(void *to, unsigned int pre_size,
		unsigned int current_size)
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
