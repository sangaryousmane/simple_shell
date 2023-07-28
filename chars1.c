#include "main.h"


/**
* _putchar - writes a character
* @chr: character to write
* Return: 1 on success
*/
int _putchar(char chr)
{
	return (write(1, &chr, 1));
}



/**
* _strncopy - copy a string of certain byte
* @dest: the destination string
* @src: the source string
* @n:the number bytes
* Return: the copied string
*/
char *_strncopy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}

	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}



/**
* _strlen - the string length
* @s: the string of characters
* Return: the string  length
*/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}


/**
 * str_to_int - convert a string to integer
 * @s:  the string
 * Return: the converted int
 */
int str_to_int(char *s)
{
	int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}



/**
* _puts - print a string
* @str: the string of char
* Return: nothing
*/
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
