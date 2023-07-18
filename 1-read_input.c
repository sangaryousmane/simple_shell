#include "main.h"



/**
* _getline: read user input from stdin
* Return: input of the user
* Description - handle the reading of users input
*/
char *_getline()
{
	int i, buff_size = 1024, rd_content;
	char *buff = malloc(buff_size);
	char c = 0;

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != -1 && c != '\n'; i++)
	{
		fflush(stdin);
		rd_content = read(STDIN_FILENO, &c, 1);
		if (rd_content == 0)
		{
		free(buff);
		exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
		free(buff);
		return ("\0");
		}
		if (i >= buff_size)
		{
			buff = _custom_realloc(buff, buff_size, buff_size + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	_remove(buff);
	return (buff);

}


/**
* is_delim - checks for delimeter
* @chr: the character to check
* @str: the strint to check
* Return: 0 on failure or 1 on success
*
*/
unsigned int is_delim(char chr, const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (chr == str[i])
			return (1);
		i++;
	}
	return (0);
}
/**
* _strtok - tokenize a string 
* @str: the string to tokenize
* @delim: the delimeter
* Return: next token or null
*/
char *_strtok(char *str, const char *delim)
{
	unsigned  int i = 0;
	static char *n, *t;

	if (str !=NULL)
	{
		n = str;
	}
	t = n;

	if (t == NULL)
		return (NULL);

	for (; t[i] != '\0'; i++)
	{
		if (is_delim(t[i], delim) == 0)
			break;
	}
	if (n[i] == '\0' || n[i] == '#')
	{
		n = NULL;
		return (NULL);
	}
	t = n + i;
	n = t;
	i = 0;

	while (n[i] != '\0')
	{
		if (is_delim(n[i], delim) == 1)
			break;
		i++;
	}

	if (n[i] == '\0')
	{
		n = NULL;
	}
	else
	{
		n[i] = '\0';
		n = n + i + 1;
		if (*n == '\0')
			n = NULL;
	}
	return (t);
}



