#include "shell.h"

/**
 * path - a function that handles path.
 * How? Takes the command that was typed in the shell, checks
 * in which directory inside PATH the command is located and
 * executes the command.
 * @command: the command.
 * Return: return concatenated string; otherwise: NULL.
 */

env_list *path(char *command)
{
	char *path = _getenv("PATH");
	char *token;
	env_list **head;

	token = strtok(path, ":");

        while (token != NULL)
        {
		token = str_concat(token, command);
		add_node_end(head, token);
		if (_which(*head) == 0)
		{
			if (access(*head, X_OK) == 0)
				return (*head);
			else
			{
				return (NULL);
			}
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
