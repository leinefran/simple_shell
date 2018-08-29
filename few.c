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
