#include "main.h"

/**
* _cd - directory to be changed
* @command: the command to be parsed
* @error:comand
* Return: 0 and 1
*/
int _cd(char **command, __attribute__((unused))int error)
{

int status;
char cwd[PATH_MAX];
char *pwd =  getenv("PWD");
status = 1;

if (!command[1])
	status = chdir(getenv("$HOME"));
else if (str_cmp(command[1], "-") == 0)
{
	status = chdir("OPWD");
}
else
{
status = chdir(command[1]);
}

if (status == -1)
{
perror("$hsh");
return (-1);
}
else
{
getcwd(cwd, sizeof(cwd));
setenv("OPWD", pwd, 1);
setenv("PWD", cwd, 1);
}
return (0);
}




/**
 * _env- enviironment variable
 * @command: command parsed
 * @error: command
 * Return: 0
 */

int _env(__attribute__((unused)) char **command,
__attribute__((unused)) int error)
{

size_t i;
int len;



for (i = 0;  environ[i] != NULL; i++)
{
len = string_len(environ[i]);
write(1, environ[i],  len);
write(STDOUT_FILENO, "\n", 1);
}
return (0);
}

/**
*_echo - Execute Echo
*@error:Statue Of Last Command Excuted
*@command: Parsed Command
* Return: Always 0
*/
int _echo(char **command, int error)
{
    char *p;
    unsigned int process_id = getppid();

    if (_strncompare(command[1], "$?", 2) == 0) {
        print_number_in(error);
        DISPLAY_TO_STDOUT("\n");
    } else if (_strncompare(command[1], "$$", 2) == 0) {
        _int_print(process_id);
        DISPLAY_TO_STDOUT("\n");

    } else if (_strncompare(command[1], "$PATH", 5) == 0) {
        p = getenv("PATH");
        DISPLAY_TO_STDOUT(p);
        DISPLAY_TO_STDOUT("\n");
        free(p);
    }
    else
    {
        return (handle_display(command));
    }
    return (1);
}
