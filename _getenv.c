#include "main.h"



/**
 * _getenv - gets environment variable's name
 * @name: the name
 * Return: the value or NULL
 */
char *_getenv(char *name)
{
	size_t l;
	size_t v;
	char *value;
	int i, x, j;

	l = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncompare(name, environ[i], l) == 0)
		{
			v = _strlen(environ[i]) - l;
			value = malloc(sizeof(char) * v);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = l + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}
