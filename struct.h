#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

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

int main(int ac, char **av, char **env);
char *stringdup(const char *str);
char *_getenv(const char *name);
void print_dir(char *name, env_list **head)
env_list *add_node_end(p_list **head, const char s);

#endif /* _SHELL_H_ */
