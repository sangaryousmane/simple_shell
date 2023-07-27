#include "main.h"

/**
 * _custom_error - custom error
 * @input: user command
 * @count: count loop of shell
 * @argv: name of the program
 * Return: nothing
 */
<<<<<<< HEAD
void _custom_error(char **input, int count, char **argv)
=======
void _custom_error(char **argv, int count, char **input)
>>>>>>> e8fe9d1eb46e13d07c6d288d5f28cdc901cc472f
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
* handle_display - Execute Normal Echo
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
 *  _error - customize errors
 * @argv: program's name
 * @count: count errors
 * @command: the command
 * Return: nothing
 */
void _error(char *command, int count, char **argv)
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
 * print_number -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
