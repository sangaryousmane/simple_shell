#include "main.h"

/**
 * main - Entry point
 * @argc: counts of arg
 * @argv: values passed
 * Return: exit status
 */
int main(int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, status = 1, st = 0;
	(void) argc;

	if (argv[1] != NULL)
	{
		read_(argv[1], argv);
	}
	signal(SIGINT, _exit_handler);
	while (status)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			DISPLAY_TO_STDOUT("$$$ ");
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			check_file(cmd, input, argv, counter);
		}
		else if (builtin(cmd) == 0)
		{
			st = handler(cmd, st);
			_free(cmd, input);
			continue;
		}
		else
		{
			st = checkcmd(cmd, input, counter, argv);

		}
		_free(cmd, input);
	}
	return (status);
}


/**
 * builtin - check for builtin
 * @cmd: the command to check
 * Return: 0 Succes -1 Fail
 */
int builtin(char **cmd)
{
	_command built[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((built + i)->command)
	{
		if (_strcmp(cmd[0], (built + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
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
		envi[i] = _strdup(environ[i]);
		i++;
	}
	envi[i] = NULL;
}
