#include "shell.h"

/**
 * path-directories - a function that prints each directory contained in the
 * the environment variable PATH, one directory per line.
 * add directories to the nodes on the Linked List.
 * @name: the variable to be compared with environ.
 * Return: char.
 */
void print_pathdir(char *name, p_list **head)
{
        char *str = _getenv(name);
        char *token;

        token = strtok(str, ":");
        add_node_end(head, token);

        while (token != NULL)
        {
                write(1, token, strlen(token));
                token = strtok(NULL, ":");
                add_node_end(head, token);
                putchar('\n');
        }
}
