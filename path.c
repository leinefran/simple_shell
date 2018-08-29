#include "shell.h"
/**
 * few - fork, execute, wait function
 * @c_pid: child process
 * @arr: double pointer to array of strings
 * @line_counter: the number of loops from getline
 * Return: 0 or -1
 */
int few(pid_t c_pid, char **arr, int line_counter)
{
	int status;

	c_pid = fork();

	if (c_pid == -1)
	{
		perror("fork() error: ");
		return (-1);
	}
	if (c_pid == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
		{
			error(arr[0], line_counter, 1);
			exit(99);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
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
	char *path_copy = stringdup(path_original);
	char *token, *ptr = arr[0], *cats;
	pid_t c_pid = 0;
	if (_which(arr[0]) == 0)
	{
		if (access(arr[0], X_OK) == 0)
		{
			few(c_pid, arr, line_counter);
			free(path_copy);
		}
		else
		{
			error(arr[0], line_counter, 1);
			free(path_copy);
		}
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
					few(c_pid, arr, line_counter);
					free(cats);
					free(path_copy);
					return (0);
				}
				else
				{
					/* files exist, but access is denied */
					error(arr[0], line_counter, 1);
					break;
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
