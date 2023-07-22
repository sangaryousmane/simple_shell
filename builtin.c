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
char cwd[PATH_MAX_LEN];
status = 1;
char *pwd =  getenv("PWD");

if (!command[1])
	status = chdir(getenv("$HOME"));
else if (Str_cmp(command[1], "-") == 0)
{
	status = chdir("OPWD");
}
else
{
status = chdir(command[1]);
}

if (status == -1)
	perror("$hsh");
return (-1);
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
__attribute__((unused)) int error) {

size_t i;
int len;
static char  *env;


for (i = 0;  env[i] != NULL; i++)
{
len = string_len(env[i]);
write(1, env[i],  len);
write(STDOUT_FILENO, "\n", 1);
}

/**
*_echo - Execute Echo
*@error:Statue Of Last Command Excuted
*@command: Parsed Command
* Return: Always 0
*/



int _echo(char **command, int error)
{
char *p = getenv("PATH");
unsigned int pid;
pid = getppid();

if (!command[1])
{
return (handle_display(command));
}
else if (str_cmp(command[1], "$?") == 0)
{
print_num(error);
}
else if (str_cmp(command[1], "$$") == 0)
{
print_num(pid);
}
else if (str_cmp(command[1], "$$PATH") == 0)
{
DISPLAY_OUT(p);
free(p);
}
else
{
return (handle_display(command));
}
DISPLAY_OUT("\n");
return (1);
}
