#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

unsigned int get_pid();
unsigned int get_ppid();
char *stringdup(const char *str);
int toksize(char *str);
char **tokanize(char *str, char **arr);
int few(pid_t c_pid, char **arr);

#endif /* _SHELL_H_ */
