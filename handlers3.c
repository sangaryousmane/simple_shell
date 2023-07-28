#include "main.h"

/**
 * _error - error based on user command and shell loop
 * @input: user command
 * @count: count loop of shell
 * @argv: name of the program
 * Return: nothing
 */
void _error(char *input, int count, char **argv)
{
	char *error;

	DISPLAY_TO_STDOUT(argv[0]);
	DISPLAY_TO_STDOUT(": ");
	error = _int_char(count);
	DISPLAY_TO_STDOUT(error);
	DISPLAY_TO_STDOUT(error);
	DISPLAY_TO_STDOUT(": ");
	DISPLAY_TO_STDOUT(input);
	DISPLAY_TO_STDOUT(": not found\n");
}


/**
* handle_display - Display output for echo command
* @command: Parsed Command
* Return: 0 on Succes -1 on Fail
*/
int handle_display(char **command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", command, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}





/**
*  _custom_error - customize errors
* @argv: program's name
* @count: count errors
* @command: the command
* Return: nothing
*/
void _custom_error(char **command, int count, char **argv)
{
	char *error = _int_char(count);

	DISPLAY_TO_STDOUT(argv[0]);
	DISPLAY_TO_STDOUT(": ");
	DISPLAY_TO_STDOUT(error);
	DISPLAY_TO_STDOUT(": ");
	DISPLAY_TO_STDOUT(command[0]);
	DISPLAY_TO_STDOUT(": Illegal number: ");
	DISPLAY_TO_STDOUT(command[1]);
	DISPLAY_TO_STDOUT("\n");
	free(error);
}



/**
* print_number - handle the printing of unsigned int
* @n: Unisigned Integer
* Return: Void
*/
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
	{
		print_number(x / 10);
	}
	_putchar(x % 10 + '0');
}
