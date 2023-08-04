#include "main.h"

/**
 * w_out - prints strings out onto screen using write
 * @message: message to be printed
 */

void w_out(char *message)
{
	write(STDOUT_FILENO, message, _strlen(message));
}

/**
 * display_prompt - displays prompt in interactive mode
 * @es: error status
 */
void display_prompt(int es)
{
	char *stable = "!!! ";
	char *err = "<<<";
	char *end = ">>> $ ";
	char *str_es;

	if (isatty(STDIN_FILENO))
	{
		str_es = malloc(sizeof(char) * (count_digits(es) + 1));
		malloc_checkptr(str_es);
		to_string(es, str_es);
		if (es == 0)
			w_out(stable);
		else
			w_out(err);
		w_out(str_es);
		w_out(end);
		free(str_es);
	}
}


/**
 * _getline - Handles the main process for interactive mode
 * @av: vector of arguments passed to the program.
 */

void _getline(char *av)
{
	int built_ret = 0;
	ssize_t getlin_ret = 0;
	size_t n = 0;
	_command cmd;

	cmd.lineptr = NULL, cmd.copy = NULL, cmd.tokens = NULL;
	cmd.es = 0, cmd.ln = 0, cmd.av = NULL;
	cmd.av = av;
	while (1)
	{
		display_prompt(cmd.es);

		getlin_ret = getline(&(cmd.lineptr), &n, stdin);
		getret(&cmd, getlin_ret);
		cmd.ln++;

		if (cmd.lineptr == NULL || _strcmp(cmd.lineptr, "\n") == 0)
			continue;
		cmd.lineptr[getlin_ret - 1] = '\0';

		cmd.copy = malloc(sizeof(char) * getlin_ret);
		malloc_checkptr(cmd.copy);
		str_cpy(cmd.copy, cmd.lineptr);
		cmd.tokens = splitstr(cmd.lineptr, cmd.copy);
		if (cmd.tokens == NULL)
			continue;
		built_ret = ch_builtin(&cmd);
		if (built_ret != 0)
			continue;

		cmd.es = 0;

		forking(&cmd);
	}
}
