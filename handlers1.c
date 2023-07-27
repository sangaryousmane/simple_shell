#include "main.h"


/**
 * _cd - navigate to another directory
 * @cmd: the command
 * @er: status
 * Return: 0 on success, 1 on fail
 */
int _cd(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
	{
		value = chdir(getenv("HOME"));
	}
	else if (str_cmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
	{
		value = chdir(cmd[1]);
	}

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}


/**
 * _env - Display Enviroment Variable
 * @cmd:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */
int _env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * display_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */
int display_help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * _echo - Excute Echo Cases
 * @st: Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int _echo(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncompare(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		DISPLAY_TO_STDOUT("\n");
	}
	else if (_strncompare(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		DISPLAY_TO_STDOUT("\n");

	}
	else if (_strncompare(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		DISPLAY_TO_STDOUT(path);
		DISPLAY_TO_STDOUT("\n");
		free(path);

	}
	else
		return (handle_display(cmd));

	return (1);
}
