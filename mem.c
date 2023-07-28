#include "main.h"



/**
* _custom_realloc -  a custom function that reallocates memory
* @ptr: the void pointer
* @prev: prev size
* @new_size: current size
* Return: nothing
*/
void *_custom_realloc(void *ptr, unsigned int prev, unsigned int new_size)
{
	void *result;

	if (new_size == prev)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		_fill(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcopy(result, ptr, prev);
		free(ptr);
	}
	return (result);

}

/**
 * _free - Frees all allocated memories
 * @ppttr: the double pointer
 * @ptr: the single pointer
 * Return: Void
 */
void _free(char **ppttr, char *ptr)
{
	free(ppttr);
	free(ptr);
	ppttr = NULL;
	ptr = NULL;
}


/**
 * _memcopy - Copy Byte From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size (How Much You Will Copy)
 *Return: Void Pointer
 */
char *_memcopy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _fill - fill an array
 * @a: the void pointer
 * @num: a number
 * @length: lenth of the int
 *Return: Void Pointer
 */
void *_fill(void *a, int num, unsigned int length)
{
	char *ptr = a;
	unsigned int i = 0;

	while (i < length)
	{
		*ptr = num;
		ptr++;
		i++;
	}
	return (a);
}
