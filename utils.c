#include "main.h"


/**
* _getenv - gets environment variable
* @name: name of the env variable
* Return: value of env variable else NULL
*/
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int k, x, j;

	nl = string_len(name);
	for (k = 0 ; environ[k]; k++)
	{
		if (_strncompare(name, environ[k], nl) == 0)
		{
			vl = string_len(environ[k]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("Error");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[k][x]; x++, j++)
			{
				value[j] = environ[k][x];
			}
			value[j] = '\0';
			return (value);
		}
	}

	return (NULL);
}



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


/**
* _free - free and reassigned
* @ppttr: double points
* @ptr: single point
*/
void _free(char **ppttr, char *ptr)
{
	free(ppttr);
	free(ptr);
	ppttr = NULL;
	ptr = NULL;
}
