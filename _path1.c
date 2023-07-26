#include "main.h"

/**
* _strcopy - Copie Source To Destination Char
* @destination: the destination string
* @source: the source string
* Return: desination
*/
char *_strcopy(char *destination, char *source)
{
	int i = 0;
	
	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}

/**
 * _str_concat - Concatinates two strings
 * @dest: the first string
 * @src: the second string
 * Return: the concatenated string
 */
char *_str_concat(char *dest, char *src)
{
	char *concat = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (concat);
}



/**
 * _strncompare - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String
 * @n: bytes
 *
 * Return:  1 on error, 0 on success
 */
int _strncmpare(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}


/**
 * _strdup - Duplicate A String
 * @str: the string
 * Return: Duplicate String Failed Null
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *s2;

	len = _strlen(str);
	s2 = malloc(sizeof(char) * (len + 1));
	
	if (s2 == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		s2[i] = str[i];
	}

	return (s2);
}
