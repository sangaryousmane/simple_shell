#include "main.h"



/**
* _isalpha - checks for alphabet
* @c: character
* Return: 1 if true and 0 otherwise
*/
int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


/**
* checkcmd - checks and exit shell
* @cmd: the parsed command
* @input_: input from user
* @counter: time of shell's execution
* @argv: args list
* Return: 0 on success, -1 for wrong cmd and 1 on null
*/
int checkcmd(char **cmd, char input_, int counter, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncompare(*cmd, "./", 2) != 0 &&
				_strncompare(*cmd, "/", 1) != 0)
		{
			cmd_path(cmd);
		}
		if (execve(*cmd, cmd, environ) == -1)
		{
			_error(cmd[0], counter, argv);
			free(input_);
			free(cmd);
			exit(1);
		}
		return (0);
	}
	wait(&status);
	return (0);
}

