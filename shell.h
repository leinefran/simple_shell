#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
/**
 * struct environ_list - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct environ_list
{
	char *str;
	struct environ_list *next;
} env_list;

void sighand(int signum);
extern char **environ;
void print_env(void);
void error(char *str, int line_counter, int flag);
int _strlen(char *s);
void rev_string(char *s);
char *_itoa(int n);
unsigned int get_pid(void);
unsigned int get_ppid(void);
char *stringdup(const char *str);
int toksize(char *str);
char **tokenize(char *str);
int few(pid_t c_pid, char **arr, int line_counter);
int str_comp(char **arr, int size);
char *_getenv(const char *name);
int _which(char *file);
char *str_concat(char *s1, char *s2, int flag);
int path(char **arr, int line_counter);


#endif /* _SHELL_H_ */
