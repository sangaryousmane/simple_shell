
#include "main.h"

/**
* _getline - read user input from stdin
* Return: the input
*/
char *_getline()
{
	int i;
	int _size = 1024, rd;
	char c = 0;
	char *buffer = malloc(_size);

	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;

	while (c != EOF && c != '\n')
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (i >= _size)
		{
			buffer = _custom_realloc(buffer, _size, _size + 1);
			if (buffer == NULL)
			{
				return (NULL);
			}
		}
		i++;
	}
	buffer[i] = '\0';
	_remove(buffer);
	return (buffer);
}


/**
* mul_env - multi environment variables
* @env: double point arr
* Return: nothing
*/
void mul_env(char **env)
{
	int i = 0;

	while (environ[i])
	{
		env[i] = _strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
}
