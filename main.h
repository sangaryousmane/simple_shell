#ifndef MAIN_H
#define SASH_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>


#define wexitstat(status) (((status) >> 8) & 0xff)
typedef unsigned int usint;

extern char **environ;

/**
 * struct _shellbuilts - struct of global variables
 * @lineptr: string containing command line args
 * @copy: copy of string containing command line args
 * @tokens: tokenized 2d array of command line arguments
 * @es: error status of program
 * @ln: line number
 * @av: executable name
 */

typedef struct _shellbuilts
{
	char *lineptr;
	char *copy;
	char **tokens;
	int es;
	int ln;
	char *av;
} _command;


int _counter(int num);
void to_string(int num, char *str);
int _atoi(char *s);
int _isdigit(char *str);
int tcnt(char **tok);

int _strlen(char *str);
char *str_cpy(char *dest, char *src);
int _strncmp(const char *str1, const char *str2, size_t len);
char *_strcat(char *dest, char *source);
int _strcmp(char *s1, char *s2);

char **splitstr(char *line, char *linecopy);
void exec(char *cmd, _command  *hg);
void _getline(char *av);
void non_interactive_mode(char *av);
char *_getenv(char *path);
char *find_path(char *cmd);
int check_path(char *cmd);
void forking(_command *hg);
void display_prompt(int es);
void w_out(char *message);

int ch_builtin(_command *hg);
void _printenv(void);
void exit_args(_command *hg);
void echo_args(char **token, int *error);

void free_tokens(char **tokenarr);
void free_alloced_mem_on_exit(_command *hg);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void malloc_checkptr(char *s);
void malloc_checkdptr(char **s);
void getret(_command *cmd, ssize_t ret);
void write_cmd_err(_command *hg);
void write_exec_err(_command *hg);
void write_exec_err2(_command *hg);
void forkerr(_command *hg);

void handle_sigint(int __attribute__((unused))sig);
int letter_ch(char s[], const char *part);
char *str_tok(char str[], const char *part);

#endif
