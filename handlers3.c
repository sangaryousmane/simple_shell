#include "main.h"

/**
 * _custom_error - custom error
 * @input: user command
 * @count: count loop of shell
 * @argv: name of the program
 * Return: nothing
 */
void _custom_error(char *input, int count, char **argv)
{
	char *error;

	DISPLAY_TO_STDOUT(argv[0]);
	DISPLAY_TO_STDOUT(": ");
	error = _itoa(count);
	DISPLAY_TO_STDOUT(error);
	DISPLAY_TO_STDOUT(error);
	DISPLAY_TO_STDOUT(": ");
	DISPLAY_TO_STDOUT(input);
	PRINTER(": not found\n");
}
