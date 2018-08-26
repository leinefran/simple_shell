#include "shell.h"

/**
 * few - fork, execute, wait function
 * @c_pid: child process
 * @arr: double pointer to array of strings
 * Return: 0 or -1
 */
int few(pid_t c_pid, char **arr)
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
			error(arr[0]);
			exit(99);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
