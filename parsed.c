#include "main.h"

/**
* parse_cmd - parsed a line of user input
* @input: the input to parsed
* Return: string
*/
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i;
	int _size = 1024;

	if (input == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * _size);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;
	return (tokens);
}
