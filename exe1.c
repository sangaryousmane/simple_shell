#include "main.h"


/**
 * read_ - Read Command From File
 * @filename: name of the file
 * @argv: the program's name
 * Return: -1 or  0
 */
void read_(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		_parsed(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}




/**
 * _parsed - parsed command
 * @line: read line from a file
 * @counter: counter for erro
 * @fp: the file descriptor
 * @argv: name of the program
 * Return : nothing
 */
void _parsed(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);

		if (_strncompare(cmd[0], "exit", 4) == 0)
		{
			exit_(cmd, line, fp);
		}
		else if (builtin(cmd) == 0)
		{
			st = handler(cmd, st);
			free(cmd);
		}
		else
		{
			st = checkcmd(cmd, line, counter, argv);
			free(cmd);
		}
}




/**
* exit_ - Exit Shell Case Of File
* @line: read a line from this file
* @cmd: the parsed command
* @fd: the file descriptor
* Return : nothing
*/
void exit_(char **cmd, char *line, FILE *fd)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	status = str_to_int(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
