#include "shell.h"

/**
 * few - fork, execute, wait function
 * @c_pid: child process
 * @arr: double pointer to array of strings
 * @str: string to free
 * Return: 0 or -1
 */
int few(pid_t c_pid, char **arr, char *str)
{
	c_pid = fork();
	int status, i, j;

	if (c_pid == -1)
	{
		perror("fork() error: ");
		return (-1);
	}
	if (c_pid == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
		{
			perror("error ");
			exit(99);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
