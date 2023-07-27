#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#define DISPLAY_TO_STDOUT(e) (write(STDOUT_FILENO, e, _strlen(e)))

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

/** utility commands **/
int _putchar(char c);
int str_to_int(char *str);
int _strlen(char *str);
void _remove(char *b);
char *_memcopy(char *d, char *src, unsigned int n);
void *_fill(void *arr, int element, unsigned int len);
void *_custom_realloc(void *to, unsigned int pre_size, unsigned int current_size);
char *_strncpy(char *dest, char *src, int n);


/** command for handling commandline args and and string **/
int _isalpha(int c);
int checkcmd(char **cmd, char *input_, int counter, char **argv);
void _exit_handler(int signal);
char *_getline();
void exit_(char **command, char *line_read, FILE *fd);
void _free(char **ppttr, char *ptr);
void check_file(char *line_read, int c, FILE *file, char **argv);
int _strncompare(const char *str1, const char *str2, size_t n);
char **parse_cmd(char *input_);
char *_strcopy(char *destination, char *source);
char *_strdup(char *str);
void _parsed(char *line, int counter, FILE *fp, char **argv);

/** Commands for tokenization **/
char *_strtok(char *str, const char *delim);
unsigned int is_delim(char chr, const char *str);
char *_int_char(unsigned int n);
void _rev(char *arr, int len);
void mul_env(char **env);

/** Builtin  commands */
void _cmd(char **cmd, char *input_, char **argv, int c);
int builtin(char **cmd);
int str_cmp(char *str1, char *str2);
int handler(char **command, int error);
void read_(char *name, char **argv);
void _error(char **user_input, int count, char **argv);
int handle_display(char **command);

/** commands for path finding **/
int len_int(int n);
int _env(__attribute__((unused)) char **command, __attribute__((unused)) int error);
int _cd(char **command, __attribute__((unused))int error);
int _echo(char **command, int error);
int cmd_path(char **command);
char *_build_command(char *token, char *value);
char *_str_concat(char *destination, char *source);
void _custom_err(char **argv, int c, char **cmd);
char *_getenv(char *name);
void print_number(unsigned int n);
void _char_print(int c);
void _puts(char *str);
void  exit_bul(char **cmd, char *input, char **argv, int c);
void print_number_in(int n);
#endif
