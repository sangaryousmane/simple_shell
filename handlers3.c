#include "main.h"



/**
* _cmd - exit status for the shell
* @cmd: the command parsed
* @input_: user input
* @argv: Program name
* @count: to count the execution
* Return: nothing
*/
void _cmd(char **cmd, char *input_, char **argv, int count)
{
	int s, i = 0;

	if (cmd[1] == NULL)
	{
		free(input_);
		free(cmd);
		exit(0);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_custom_err(argv, counter, cmd);
			break;
		}
		else
		{
			s = str_to_int(cmd[1]);
			free(input_);
			free(cmd);
			exit(s);
		}
	}
}

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


/**
* builtin - check shell built in
* @command: the parsed command
* Return: 0 on success and -1 on Fail.
*/
int builtin(char **command)
{
	int i = 0;
	_command fun[] = {
		{"echo", NULL},
		{"cd", NULL},
		{"help", NULL},
		{NULL, NULL}
	};
	     if (*command == NULL)
	     {
		     return (-1);
	     }
	     
	     while ((fun + i)-> command)
	     {
		     if (str_cmp(command[0], (fun+i)->command) == 0)
			     return (0);
		     i++;
	     }
	     
	     return (-1);
}


/**
* handler - handles builtin commands
* @error: last execution status
* @command: the parsed command
* Return: executed builtin
*/
int handler(char **command, int error)
{
	 _command builtin[] = {
		 {"echo", _echo},
		 {"env", _env},
		 {"cd", _cd},
		 {NULL, NULL}
	 };
	 int i = 0;

	 while ((builtin+i)->command)
	 {
		 if (cmp_str(command[0], (builtin + i)->command) == 0)
		 {
			 return ((builtin + i) ->is_builtin(command, error));
		 }
		 i++;
	 }
	 return (-1);
}
