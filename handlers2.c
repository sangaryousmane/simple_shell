#include "main.h"

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
