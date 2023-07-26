#include "main.h"


/**
 * path_cmd -  Search In $PATH For Excutable Command
 * @command: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int cmd_path(char **command)
{
	char *path, *token, *cmd_path;
	struct stat buffer;

	path = _getenv("PATH");
	token = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*command, token);
		if (stat(cmd_path, &buffer) == 0)
		{
			*command = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		token = _strtok(NULL, ":");
	}
	free(path);
	return (1);
}


/**
 * _build_command - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 * Return: NULL on failure or concatenated path
 */
char *_build_command(char *token, char *value)
{

	char *command;
	size_t length;

	length = _strlen(value) + _strlen(token) + 2;
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
 * _getenv - Gets The Value Of Enviroment Variable By Name
 * @name: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], nl) == 0)
		{
			vl = _strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
