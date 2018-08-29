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

int path(char **arr, int line_counter)
{
	char *path_original = _getenv("PATH");
	char *path_copy = strdup(path_original);
	char *token, *ptr = arr[0], *cats;
	pid_t c_pid = 0;

	if (_which(arr[0]) == 0)
	{
		if (access(arr[0], X_OK) == 0)
			few(c_pid, arr, line_counter);
		else
			error(arr[0], line_counter, 1);
	}
	else
	{
		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			cats = str_concat(token, ptr, 1);
			if (_which(cats) == 0)
			{
				if (access(cats, X_OK) == 0)
				{
					arr[0] = cats;
					free(cats);
					free(path_copy);
					few(c_pid, arr, line_counter);
					return (0);
				}
				else
				{
					/* files exist, but access is denied */
					error(arr[0], line_counter, 1);
				}
			}

			token = strtok(NULL, ":");
			free(cats);
		}
		free(path_copy);
		error(arr[0], line_counter, 0);
	}
	return (-1);
}
