#include "main.h"

/**
 * write_exec_err2 - writes error output for exit argument error
 * @cmd: struct of global variables
 */

void write_exec_err2(_command *cmd)
{
	char *str = malloc(sizeof(char) * (count_digits(cmd->ln) + 1));

	malloc_checkptr(str);
	to_string(cmd->ln, str);

	write(STDERR_FILENO, cmd->av, _strlen(cmd->av));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd->tokens[0], _strlen(cmd->tokens[0]));
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, cmd->tokens[1], _strlen(cmd->tokens[1]));
	write(STDERR_FILENO, "\n", 1);
	free(str);
}
