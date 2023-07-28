#include "main.h"



/**
 * _strncompare - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncompare(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	if (s1 == NULL)
		return (-1);

	while (i < n && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}


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



/**
 * check_file - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @c:Excute Count
 * Return: Void (Exit Statue)
 */
void  check_file(char **cmd, char *input, char **argv, int c)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_custom_error(argv, c, cmd);
			break;
		}
		else
		{
			status = str_to_int(cmd[1]);
			free(input);
			free(cmd);
			exit(status);
		}
	}
}

