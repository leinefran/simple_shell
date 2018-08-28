#include "shell.h"
#include <string.h>
/**
 * path - a function that handles path.
 * How? Takes the command that was typed in the shell, checks
 * in which directory inside PATH the command is located and
 * executes the command.
 * @arr: an array of string pointers.
 * @line_counter: the loop counter from getline
 * Return: return concatenated string; otherwise: NULL.
 */

char *path(char **arr, int line_counter)
{
	char *path_original = _getenv("PATH");
	char *path_copy = strdup(path_original);
	char *token, *ptr = arr[0], *cats;

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		cats = str_concat(token, ptr, 1);
		if (_which(cats) == 0)
		{
			if (access(cats, X_OK) == 0)
			{
				free(path_copy);
				return (cats);
			}
			else
			{
				free(cats);
				free(path_copy);
				/* files exist, but access is denied */
				error(arr[0], line_counter, 2);
				return (NULL);
			}
		}

		token = strtok(NULL, ":");
		free(cats);
	}
	free(path_copy);
	return (NULL);
}
