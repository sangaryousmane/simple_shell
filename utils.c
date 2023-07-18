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
	if (str1 != str2)
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

