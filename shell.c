#include "shell.h"
/**
 * main - simple shell program
 * Return: 0 always success
 */
int main(void)
{
	/*unsigned int pid, ppid;*/
	ssize_t read = 0;
	char *buff = NULL, **arr;
	size_t size = 0;
	int result, tok_size = 0, len = 0, line_counter = 0;

	while (1)
	{
		/* reset size and buffer after every loop */
		size = 0;
		buff = NULL;

		if (isatty(0))
		{
		/* write out prompt */
			write(STDIN_FILENO, "$ ", 2);
		}
		/* get input from user and store into buffer */
		read = getline(&buff, &size, stdin);
		line_counter++;
		/* if getline fails, it will return -1 to read */
		if (read == -1)
		{
			free(buff);
			write(1, "\n", 1);
			return (0);
		}

		/* if buffer exists and first index is not a newline */
		if (buff && buff[0] != '\n')
		{
			/* count length of buffer input */
			len = _strlen(buff);
			if (buff[len - 1] == '\n')
				buff[len - 1] = '\0';

			/* count number of tokens in buffer */
			tok_size = toksize(buff);
			if (tok_size == -1)
				break;
			if (tok_size == 0)
				continue;

			/* put tokens inside array */
			arr = tokenize(buff);

			/* checks if 'env' or 'exit' command is entered */
			result = str_comp(arr, tok_size);
			if (result == 0)
			{
				free(arr);
				free(buff);
				exit(0);
			}
			else if (result == 2)
			{
				free(arr);
				free(buff);
				continue;
			}
			/* sending the input to the path function */
			/* works for single commands like 'ls' */
			path(arr, line_counter);
		}

		if (buff && buff[0] == '\n')
		{
			free(buff);
			continue;
		}
		free(buff);
		free(arr);
	}
	return (0);
}
