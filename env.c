#include "main.h"

/**
* _setenv - sets environment variable
* @name: variable's name
* @value: the value
* @overwrite: overites
* Return: -1 on failure, 0 on success
*/
int _setenv(const char *name, const char *value, int overwrite)
{

	char *var = getenv(name);
	int numVars = 0, i;

	if (var != NULL && !overwrite)
	{
		return (0);
	}
	while (environ[numVars] != NULL)
	{
		numVars++;
	}

	char **newEnviron = malloc((numVars + 2) * sizeof(char *));
	if (newEnviron == NULL)
	{
		return (-1);
	}
	for (i = 0; i < numVars; i++)
	{
		newEnviron[i] = environ[i];
	}

	char *newVar = malloc(strlen(name) + strlen(value) + 2);
	if (newVar == NULL)
	{
		free(newEnviron);
		return (-1);
	}
	sprintf(newVar, "%s=%s", name, value);
	newEnviron[numVars] = newVar;
	newEnviron[numVars + 1] = NULL;
	environ = newEnviron;
	return (0);
}





/**
* _unsetenv - unset an environement variable
* @name: name of the variable
* Return: -1 on failure and 0 on success.
**/
int _unsetenv(const char *name)
{
	int numVars = 0, newIndex = 0;
	int i;

	while (environ[numVars] != NULL)
	{
		numVars++;
	}

	char **newEnviron = malloc((numVars + 1) * sizeof(char *));	
	if (newEnviron == NULL)
	{
		return (-1);
	}
	for (i = 0; i < numVars; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) != 0 || 
				environ[i][strlen(name)] != '=')
		{
			newEnviron[newIndex++] = environ[i];
		}
	}
	newEnviron[newIndex] = NULL;
	environ = newEnviron;
	return (0);
}
