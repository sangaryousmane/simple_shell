#include "main.h"

/**
 * exec - function utilises execve() to execute standard commands in path
 * @hg: struct of global variables.
 * @cmd: command that is entered in command line
 */
void exec(char *cmd, _command *hg)
{
	char **envcpy = environ;

	execve(cmd, hg->tokens, envcpy);
	if (errno == EACCES)
	{
		write_exec_err(hg);
		hg->es = 126;
	}
	free_alloced_mem_on_exit(hg);
	_exit(hg->es);
}
