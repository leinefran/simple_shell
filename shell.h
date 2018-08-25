#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

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

int _strlen(char *s);
unsigned int get_pid();
unsigned int get_ppid();
char *stringdup(const char *str);
int toksize(char *str);
char **tokenize(char *str);
int few(pid_t c_pid, char **arr);
int str_comp (char **arr);
int exit_shell(char **arr, int size);
char *_getenv(const char *name);
int _which(char *file);
env_list *path(char *command, env_list **head);
char *str_concat(char *s1, char *s2);



#endif /* _SHELL_H_ */
