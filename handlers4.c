#include "main.h"


/**
 *  _error - customize errors
 * @argv: program's name
 * @count: count errors
 * @command: the command
 * Return: nothing
 */
void _error(char **argv, int count, char **command)
{
        char *error = _itoa(count);

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
/**
 * print_number_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
