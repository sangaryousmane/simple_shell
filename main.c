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
	char *input, **cmd;
	int count = 0;
	int exit_status = 1, success_status = 0;

	if (argv[1])
	{
		read(argv[1], argv);
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

		/** Implement consult history here */

		free(cmd);
		free(input);
	}
	return (exit_status);

}
