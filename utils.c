#include "main.h"


/**
 *  str_cmp - Compare Two String
 *  @str1: string one
 *  @str2: string two
 *  Return: 0 on success
 */
int str_cmp(char *str1, char *str2)
{
	int status = 0, i, length1, length2;

	length1 = string_len(str1);
	length2 = string_len(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (length1 != length2)
		return (1);
	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			status = str1[i] - str2[i];
			break;
		}
		else
			continue;
	}
	return (status);
}


/**
 * read_ - read commands from file
 * @name: file's name
 * @argv: name of the program
 * Return: -1 on error, otherwise 0
 */
void read_(char *name, char **argv)
{
	size_t len = 0;
	int count = 0;
	char *line_read = NULL;
	ssize_t s;
	FILE *file;

	file = fopen(name, "r");

	if (file == NULL)
	{
		exit(1);
	}
	s = getline(&line_read, &len, file);
	while (s != -1)
	{
		check_file(line_read, count, file, argv);
		count++;
	}
	if (line_read)
		free(line_read);
	fclose(file);
	exit(0);
}
