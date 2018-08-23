#include "shell.h"

/**
 * add_node_end - a function that adds a new node at the end of
 * a path_list p_list;.
 * @head: points to the address of the first node.
 * @s: the string.
 * Return: the address of the new element, or NULL if it failed.
 */
env_list *add_node_end(env_list **head, char *s)
{
        env_list *new_node, *tmp;

        tmp = *head;

        new_node = malloc(sizeof(env_list));
        if (new_node == NULL)
                return (NULL);

        new_node->str = s;
        new_node->next = NULL;

        if (*head == NULL)
                *head = new_node;
        else
        {
                while (tmp->next != NULL)
                        tmp = tmp->next;
                tmp->next = new_node;
        }
        return (new_node);
}
