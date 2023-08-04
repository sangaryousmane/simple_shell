#include "main.h"

/**
 * forkerr - handles for errors
 * @cmd: the command
 */

void forkerr(_command *cmd)
{
	if (errno == EACCES)
	{
		cmd->es = 126;
		write_exec_err(cmd);
	}
	else
	{
		cmd->es = 127;
		write_cmd_err(cmd);
	}
}


/**
* forking - initializes forking the main process for child process...
* @command: struct of global variables.
*/
void forking(_command *command)
{
	pid_t fret;
	int status, tracker = 0;
	char *cmd = command->tokens[0];

	if (command->tokens[0][0] != '/' && command->tokens[0][0] != '.')
	{
		tracker = 1;
		cmd = find_path(command->tokens[0]);
	}
	if (cmd == NULL || access(cmd, F_OK) == -1)
	{
		forkerr(command);
	}
	else
	{
		fret = fork();
		if (fret == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (fret == 0)
			exec(cmd, command);
		else
		{
			wait(&status);
			command->es = wexitstat(status);
		}
	}

	free_alloced_mem_on_exit(command);
	if (tracker)
	{
		free(cmd);
	}
}
