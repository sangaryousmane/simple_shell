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
		read_(argv[1], argv);
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
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
