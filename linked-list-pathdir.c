#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * list_pathdir - a function that builds a linked list of
 * the PATH directories.
 * @name: the variable to be compared with environ.
 * @head: points to the address of the first node.
 * Return: char.
 */
void list_pathdir(const char *name, p_list **head)
{
	p_list *new_node, *tmp;
	int i = 0;
	char *s = _getenv(name);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	*head = new_node;
	new_node->str = strtok(s, ":");
	new_node->next = NULL;

	tmp = *head;
	while (s != NULL)
	{
		printf("%s\n", new_node->str);
		tmp = tmp->next;
		tmp->next = new_node;
		new_node->str = strtok(NULL, ":");
	}
	return (new_node);
}
void main()
{
	char *name = "PATH";
	p_list *head;

	head = NULL;
	list_pathdir(&head);

}
