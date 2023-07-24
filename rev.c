#include "main.h"



/**
* _rev - Reverse an  Array
* @arr:Array
* @len:Length
* Return: Void
*/
void _rev(char *arr, int len)
{
int i = 0;
char a;

for (i = 0; i < (len / 2);  i++)
{
a = arr[i];
arr[i] = arr[len - 1 - i];
arr[len - 1 - i] = a;
}
}



/**
 * _error - Display shell errors
 * @user_input: Accepts user input
 * @count: counter
 * @argv: argument list
 * Return: nothing
 */
void _error(char *_input, int count, char **argv)
{
	char *err;

	DISPLAY_TO_STDOUT(argv[0]);
	DISPLAY_TO_STDOUT(": ");
	
	err = _int_char(count);
	
	DISPLAY_TO_STDOUT(err);
	
	free(err);
	
	DISPLAY_TO_STDOUT(": ");
	DISPLAY_TO_STDOUT(_input);
	DISPLAY_TO_STDOUT(": not found\n");
}

