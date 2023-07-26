#include "main.h"



/**
 * _remove - removes all after #
 * @buffer: the input;
 * Return: nothing
 */
void _remove(char *buffer)
{
        int i = 0;

        while (buffer[i] != '\0')
        {
                if (buffer[i] == '#')
                {
                        buffer[i] = '\0';
                        break;
                }
                i++;
        }
}



/**
* is_delim - checks for delimiter
* @chr: the character
* @str: the string
* Return: success 1 otherwise 0
*/
unsigned int is_delim(char chr, const char *str)
{
	unsigned int j = 0;

	while (str[j] != '\0')
	{
		if (chr == s[j])
			return (1);
		j++;
	}
	return (0);
}



/**
* _strtok - tokenizes a string
* @_input: the string of characters
* @d: the delimiter
* Return: NULL or a pointer to the next token
*/
char *_strtok(char *_input, const char *d)
{
	static char *ts;
	static char *nt;
	unsigned int i = 0;

	if (_input != NULL)
		nt = _input;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	while (ts[i] != '\0')
	{
		if (is_delim(ts[i], d) == 0)
			break;
		i++;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;

	while (nt[i] != '\0')
	{
		if (is_delim(nt[i], d) == 1)
			break;
		i++;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}
