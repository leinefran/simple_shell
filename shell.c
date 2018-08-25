#include "shell.h"
/**
 * main - simple shell program
 * Return: 0 always success
 */
int main(void)
{
	/*unsigned int pid, ppid;*/
	ssize_t read = 0;
	char *buff = NULL, **arr, *cats = NULL;
	size_t size = 0;
	int ex, tok_size = 0, len = 0;
	pid_t c_pid = 0;

	/*pid = get_pid();*/
	/*ppid = get_ppid();*/
	while (1)
	{
		/* reset size and buffer after every loop */
		size = 0;
		buff = NULL;

		/* write out prompt */
		write(STDIN_FILENO, "$ ", 2);

		/* get input from user and store into buffer */
		read = getline(&buff, &size, stdin);
		/* if getline fails, it will return -1 to read */
		if (read == -1)
		{
			free(buff);
			return (0);
		}

		/* if buffer exists and first index is not a newline */
		if (buff && buff[0] != '\n')
		{
			len = strlen(buff);
			if (buff[len - 1] == '\n')
				buff[len - 1] = '\0';

			tok_size = toksize(buff);
			if (tok_size == -1)
				break;

			arr = tokenize(buff);

			ex = exit_shell(arr, tok_size);
			if (ex == 0)
			{
				free(arr);
				free(buff);
				exit(0);
			}
			cats = path(arr[0]);
			if (cats)
				arr[0] = cats;

			few(c_pid, arr);
		}

		if (buff && buff[0] == '\n')
		{
			free(buff);
			continue;
		}

		free(arr);
	}
	return (0);
}
