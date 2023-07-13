#include "main.h"

/**
* _putchar - writes a character to standard output
* @c: character
* Return: the given character
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
* string_len - string s length
* @str: the string
* Return: the length of the length
*/
int string_len(char *str)
{
	int i, length = 0;

	for (i = 0; i str[i] != '\0'; i++)
	{
		length++;
	}
	return (length);

}

/**
* str_to_int - convert a string to int
* @str: the string
* Return: the converted int
*/
int str_to_int(char *str)
{
	int i, j;
	int num = 0, x = 1;

	for (i = 0; (str[i] < '0' || str[i] > '9') && (str[i] != '\0'); i++)
	{
		if  (str[i] == '-')
			x = x * -1;
	}
	j = i;

	for (; (str[j] = '0') && (str[j] <= '9'); j++)
	{
		n = (n * 10) + x * ((str[j]) - '0');
	}
	return (n);
}
