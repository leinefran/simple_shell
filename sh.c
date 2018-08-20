#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	char *token = NULL, **arr = NULL, *str2 = NULL, *buff = NULL;
	int i = 0, count = 0, status = 0;
	size_t size = 0;
	ssize_t read = 0;
	pid_t c_pid = 0;
	struct stat st;


	while (1)
	{
		write(1, "$ ", 2);

		read = getline(&buff, &size, stdin);
		if (read == -1)
			return (-1);
		if (buff && buff[0] != '\n')
		{
			printf("size = %lu\n", size);
			str2 = strdup(buff);

			if (str2 == NULL)
			{
				return (-1);
			}
			token = strtok(buff, " ");

			if (token == NULL)
			{
				write(STDIN_FILENO, '\0', 1);
				break;
			}
			while(token != NULL)
			{
				token = strtok(NULL, " ");
				count++;
			}
			arr = malloc(sizeof(char*) * (count + 1));
			printf("count = %i\n", count);

			if (!arr)
			{
				return (-1);
			}
			arr[count] = NULL;

			token = strtok(str2, " \n");

			while (token != NULL)
			{
				arr[i] = token;
				token = strtok(NULL, " \n");
				i++;
			}

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
					perror("Error ");
					exit(99);
				}
			}
			else
			{
				wait(&status);
				free(arr);
				free(str2);
			}
			count = 0;
			i = 0;
		}
	}
	return (0);
}
