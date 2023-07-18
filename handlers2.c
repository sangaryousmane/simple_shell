#include "main.h"


/**
* parse_cmd - parse the command of the user
* @input_: user's input
* Return: an array pointer
*/
char **parse_cmd(char *input_)
{
	int count = 0, bs = 1024;
	char **parsed_t;
	char *t;

	if (input_ == NULL)
	{
		return (NULL);
	}
	parsed_t = malloc(sizeof(char *) * bs);
	if (parsed_t == NULL)
	{
		perror("hsh");
		return (NULL);
	}

	t = _strtok(NULL, "\n ");
	while (t)
	{
		parsed_t[count] = t;
		t = _strtok(NULL, "\n ");
		count++;
	}
	parsed_t[count] = NULL;
	return (parsed_t);
}

/*
* _strncompare - compare number chars for two strings
* @str1: the first string
* @str2: the second string
* @n: number of chars to compare
* Return: 1 incase of mismatch else 0
*/
int _strncompare(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	if (str1 == NULL)
	{
		return (-1);
	}
	while (i < n && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
/**
* check_file - checks command Fork
* @line_read: a line from the file
* @c: control error handling
* @file: file descriptor
* @argv: name of the program
*/
void check_file(char *line_read, int c, FILE file, char **argv)
{
	char **command;
	int status = 0;

	command = parse_cmd(line_read);

	if (_strncompare(command, line_read, file))
	{
			exit_(command, line_read, file);
	}
	else if (builtin(command) == 0)
	{
		handler(command, status);
		free(command);
	}
	else
	{
		checkcmd(command, line_read, c, argv);
		free(command);
	}
}

/**
* exit_ - exit the shell
* @line_read: a line from the file
* @command: the parse command
* @fd: the file descriptor
* Return: case of exit in a file
*/
void exit_(char **command, char *line_read, FILE *fd)
{
	int s, i = 0;

	if (command[1] == NULL)
	{
		free(line_read);
		free(command);
		fclose(fd);
		exit(errno);
	}
	while (command[1][i])
	{
		if (_isalpha(command[1][i++]) < 0)
		{
			perror("Illegal number");
		}
	}
	s = str_to_int(command[1]);
	free(line_read);
	free(command);
	fclose(fd);
	exit(s);
}

