#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strlen(char *s);
unsigned int get_pid();
unsigned int get_ppid();
char *stringdup(const char *str);
int toksize(char *str);
char **tokenize(char *str);
int few(pid_t c_pid, char **arr);
int str_comp (char **arr);
int exit_shell(char **arr, int size);
int _which(char *file);

#endif /* _SHELL_H_ */
