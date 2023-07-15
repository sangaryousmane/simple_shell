#ifndef MAIN_H
#define MAIN_H


#define DISPLAY_TO_STDOUT(e) (write(STDOUT_FILENO, e, string_len(e)))

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

int _putchar(char c);
int str_to_int(char *str);
int string_len(char *str);
void _remove(char *b);
char *_memcopy(char *d, char *src, unsigned int n);
void *_fill(void *arr, int element, unsigned int len);
void *_custom_realloc(void *to, unsigned int pre_size, unsigned int current_size);
void _exit_handler(int signal);
char *_getline();

#endif
