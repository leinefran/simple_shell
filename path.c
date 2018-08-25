#include "shell.h"

/**
 * path - a function that handles path.
 * How? Takes the command that was typed in the shell, checks
 * in which directory inside PATH the command is located and
 * executes the command.
 * @arr: an array of string pointers.
 * Return: return concatenated string; otherwise: NULL.
 */

char *path(char **arr)
{
	char *path_original = _getenv("PATH");
	char *path_copy = strdup(path_original);
	char *token, *ptr = arr[0], *cats;

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		cats = str_concat(token, ptr);
		printf("cats: %s\n", cats);
		if (_which(cats) == 0)
		{
			if (access(cats, X_OK) == 0)
			{	free(path_copy);
				return (cats);
			}
			else
			{
				free(cats);
				free(path_copy);
				return (NULL);
			}
		}
		token = strtok(NULL, ":");
		free(cats);
	}
	free(path_copy);
	return (NULL);
}
