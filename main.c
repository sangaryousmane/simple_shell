#include "main.h"


/**
* main - entry point for the simple shell
* @argc: counts of argument
* @argv: arguments values
* Return: exit status
*/
int main(int argc, char **argv)
{
	(void) argc;
	char *input;
	char **cmd;
	int exit_status = 1, success_status = 0, count = 0;

	if (argv[1])
	{
		read_(argv[1], argv);
	}
	signal(2, _exit_handler);
	while (exit_status)
	{
		count++;
		if (isatty(STDIN_FILENO))
		{
			DISPLAY_TO_STDOUT("$hsh ");
		}
		input = _getline();
		if (input[0] == '\0')
			continue;
		cmd = parse_cmd(input);
		if (str_cmp(cmd[0], "exit") == 0)
		{
			_cmd(cmd, input, argv, count);
		}
		else if (builtin(cmd) == 0)
		{
			success_status = handler(cmd, success_status);
			free(cmd);
			free(input);
			continue;
		}
		else
		{
			success_status = checkcmd(cmd, input, count, argv);
		}
		free(cmd);
		free(input);
	}
	return (exit_status);
}
