#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - a program that executes the command ls -l /tmp,
 * in 5 different child processes of same father,
 * wait for a child to exit before creating a new one;
 * return: 0 on success.
 */
int main()
{
	pid_t c_pid;
	int status;
	int i;

	char *args[] = {"/bin/ls", "-l", "/tmp/", NULL};

//creat n-child process from same parent process:
	for (i = 0 ; i < 5 ; i++)
	{
		c_pid = fork();

		if (c_pid  == -1)
		{
			perror("fork() error");
			return (-1);
		}
		if (c_pid == 0)
		{
//execute ls:
			printf("In child process (pid = %d)\n", getpid());
			if(execve(args[0], args, NULL) == -1)
				perror("error");
		}
		else // parent process
		{
			wait(&status);
			printf("I'm the parent\n");
		}
	}
	return (0);
}
