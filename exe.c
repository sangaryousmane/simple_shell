#include "main.h"

/**
 * handler - handle builtin commands
 * @cmd: the parsed command
 * @er: the error status
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int handler(char **cmd, int er)
{
	 _command bil[] = {
		{"cd", _cd},
		{"env", _env},
		{"echo", _echo},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}



/**
 * checkcmd - exit the shell
 * @cmd: the parsed command
 * @input: input of the user
 * @c: command execution
 * @argv: name of the program
 * Return: 1 on NULL, -1 wrong command, 0 on command executed
 */
int checkcmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncompare(*cmd, "./", 2) != 0 && _strncompare(*cmd, "/", 1) != 0)
		{
			cmd_path(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * _exit_handler - Handle ^C
 * @signal: Captured Signal
 * Return: nothing
 */
void _exit_handler(int signal)
{
	if (signal == SIGINT)
	{
		DISPLAY_TO_STDOUT("\n$$$ ");
	}
}
