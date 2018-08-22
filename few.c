#include "shell.h"

/**
 * few - fork, execute, wait function
 * @c_pid: child process
 * @arr: double pointer to array of strings
<<<<<<< HEAD
 * @str: string to free
=======
>>>>>>> 1d1c86171bad59db14b4a2056d290033ee4b279b
 * Return: 0 or -1
 */
int few(pid_t c_pid, char **arr)
{
	c_pid = fork();
<<<<<<< HEAD
	int status, i, j;
=======
	int status;
>>>>>>> 1d1c86171bad59db14b4a2056d290033ee4b279b

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
