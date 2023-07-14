#include "main.h"



/**
* _getline: read user input from stdin
* Return: input of the user
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
			buff = custom_realloc(buff, buff_size, buff_size+1);
			
			if (buff == NULL)
			{
				return (NULL):
			}
		}
	}

	buff[i] = '\0';
	_remove(buff);
	return (buff);

}

