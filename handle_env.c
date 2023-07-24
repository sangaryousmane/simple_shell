#include "main.h"


/**
 * _str_concat - Concatenate two strings
 * @destination:First String
 * @source:Second String
 *
 * Return: concatenated string
 */
char *_str_concat(char *destination, char *source)
{
	char *s = destination;

	while (*destination != '\0')
	{
		destination++;
	}

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (s);
}


/**
 * _build_command - Build a command
 * @token:  token
 * @value: the directory to which the command belongs
 */
char *_build_command(char *token, char *value)
{
	char *command;
	size_t length;
	
	length = string_len(value) + string_len(token) + 2;
	command = malloc(sizeof(char) * length);
	
	if (command == NULL)
	{
		return (NULL);
	}
	
	memset(command, 0, length);
	command = _str_concat(command, value);
	command = _str_concat(command, "/");
	command = _str_concat(command, token);
	return (command);
}

/**
 * _int_print - unsigned int
 * @n: unsigned int
 * Return: Void
 */
void _int_print(unsigned int n)
{
	unsigned int x = n;
	unsigned int temp = 1;

	while (x / temp > 10)
	{
        temp *= 10;
	}

	while (temp > 0)
	{
		_putchar((x / temp) + '0');
		x %= temp;
		temp /= 10;
	}
	_putchar(x % 10 + '0');
}
