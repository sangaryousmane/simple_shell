#include "main.h"



/**
 * _getenv - gets  the environment
 * @name: name
 * Return: value or NULL
 */
char *_getenv(char *name)
{
	char **env;
        size_t len;

        env = environ;
        len = _strlen(path);

        while (*env != NULL)
        {
                if (_strncmp(*env, path, len) == 0 && (*env)[len] == '=')
                {
                        return (&((*env)[len + 1]));
                }
                env++;
        }

        return (NULL);
}
