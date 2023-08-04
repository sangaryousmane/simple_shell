#include "main.h"

/**
 * malloc_checkptr - check if return is NULL and exit if condition is met
 * @s: check null string
 */

void malloc_checkptr(char *s)
{
	if (s == NULL)
		exit(EXIT_FAILURE);
}

/**
 * malloc_checkdptr - check if return is NULL and exit if condition is met
 * @s: check null 2d string
 */

void malloc_checkdptr(char **s)
{
	if (s == NULL)
		exit(EXIT_FAILURE);
}

/**
 * getret - check for getline return value and EOF condition
 * @cmd: struct of global variables
 * @ret: return of getline function
 */
void getret(_command *cmd, ssize_t ret)
{
	char new_line = '\n';

	if (cmd->lineptr == NULL)
		return;
	if (ret == -1)
	{
		free_alloced_mem_on_exit(cmd);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, &new_line, 1);
		}
		exit(cmd->es);
	}
}

/**
 * write_cmd_err - writes error output for commands not found in path
 * @cmd: struct of global variables
 */
void write_cmd_err(_command *cmd)
{
	char *str = malloc(sizeof(char) * (count_digits(cmd->ln) + 1));

	malloc_checkptr(str);
	to_string(cmd->ln, str);

	write(STDERR_FILENO, cmd->av, _strlen(cmd->av));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd->tokens[0], _strlen(cmd->tokens[0]));
	write(STDERR_FILENO, ": not found", 11);
	write(STDERR_FILENO, "\n", 1);
	free(str);
}

/**
 * write_exec_err - writes error when execve fails.
 * @cmd: struct of global variablesr
 */
void write_exec_err(_command *cmd)
{
	char *str = malloc(sizeof(char) * (count_digits(cmd->ln) + 1));
	char *message = ": Permission denied";

	malloc_checkptr(str);
	to_string(cmd->ln, str);

	write(STDERR_FILENO, cmd->av, _strlen(cmd->av));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd->tokens[0], _strlen(cmd->tokens[0]));
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
	free(str);
}
