#include "main.h"


/**
 * cmd_path-  Search In $PATH For Excutable Command
 * @command: Parsed Input of command
 * Return: 1  Failure  0  Success.
 */
int cmd_path(char **command)
{
	char *path, *token, *cmd_path;
	struct stat buffer;

	path = _getenv("PATH");
	token = _strtok(path, ":");
	while (token != NULL)
	{
		cmd_path = _build_command(*command, token);
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

