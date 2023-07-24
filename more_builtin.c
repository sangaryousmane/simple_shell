#include "main.h"

/**
* len_int - Determine Length Of Int
* @n: Given Int
* Return: Length Of Int
*/
int len_int(int n)
{
	int len;
	for (len = 0; n != 0; len++)
	{
		n /= 10;
	}
	return (len);
}


/**
* _int_char - Convert Integer To Char
* @n: Int To Convert
* Return: Char Pointer
*/
char *_int_char(unsigned int n)
{
   int len = 0, i = 0;
   char *s;


   len = len_int(n);
   s = malloc(len + 1);
   if (!s)
       return (NULL);
   *s = '\0';
   while (n / 10)
   {
       s[i] = (n % 10) + '0';
       n /= 10;
       i++;
   }
   s[i] = (n % 10) + '0';
   _rev(s, len);
   s[i + 1] = '\0';
   return (s);
}


/**
* cmd_path -  search PATH for executable cmd
* @command: the command
* Return: 1 on failure and 0  Success.
*/
int cmd_path(char **command)
{
  char *path, *value, *cmd_path;
  struct stat buf;


  path = getenv("PATH");
  value = _strtok(path, ":");
  while (value != NULL)
  {
     cmd_path = _build_command(*command, value);
     if (stat(cmd_path, &buf) == 0)
     {
        *command = strdup(cmd_path);
        free(cmd_path);
        free(path);
        return (0);
     }
     free(cmd_path);
     value = _strtok(NULL, ":");
  }
  free(path);
  return (1);
}



/**
*  _custom_err - Print Custome Error
* @argv:Program Name
* @c:Error Count
* @cmd:Command
* Return: Void
*/
void _custom_err(char **argv, int c, char **cmd)
{
	char *error = _int_char(c);
	
	DISPLAY_TO_STDOUT(argv[0]);
	DISPLAY_TO_STDOUT(": ");
	DISPLAY_TO_STDOUT(error);
	DISPLAY_TO_STDOUT(": ");
	DISPLAY_TO_STDOUT(cmd[0]);
	DISPLAY_TO_STDOUT(": Illegal number: ");
	DISPLAY_TO_STDOUT(cmd[1]);
	DISPLAY_TO_STDOUT("\n");
	free(error);
}
