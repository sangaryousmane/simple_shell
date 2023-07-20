#ifndef MAIN_H
#define MAIN_H


#define DISPLAY_TO_STDOUT(e) (write(STDOUT_FILENO, e, string_len(e)))
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>


/**
* struct  shell_builtin - execution n command handling
* @command: the command to handler
* @is_builtin: executes when a builtin is true.
*/ 
struct shell_builtin
{
	char *command;
	int (*is_builtin)(char **_line, int e);
};

typedef struct shell_builtin  _command;

int _putchar(char c);
int str_to_int(char *str);
int string_len(char *str);
void _remove(char *b);
char *_memcopy(char *d, char *src, unsigned int n);
void *_fill(void *arr, int element, unsigned int len);
void *_custom_realloc(void *to, unsigned int pre_size, unsigned int current_size);

int _isalpha(int c);
int checkcmd(char **cmd, char *input_, int counter, char **argv);
void _exit_handler(int signal);
char *_getline();
void exit_(char **command, char *line_read, FILE *fd);
void check_file(char *line_read, int c, FILE file, char **argv);
int _strncompare(const char *str1, const char *str2, size_t n);
char **parse_cmd(char *input_);

char *_strtok(char *str, const char *delim);
unsigned int is_delim(char chr, const char *str);

/** Builtin  commands */
void _cmd(char **cmd, char *input_, char **argv, int c);
int builtin(char **cmd);
int str_cmp(char *str1, char *str2);
int handler(char **command, int error);
void read_(char *name, char **argv);
#endif
