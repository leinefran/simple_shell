#include "shell.h"
/**
 * sighand - function to handle ctrl+c
 * @signum: signal number
 */
void sighand(int signum)
{
	(void)signum;
	write(1, "\n$ ", 3);
}
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
	int ex_flag = 0;

	while (1)
	{
		size = 0;
		buff = NULL;

		if (isatty(0))
			write(STDIN_FILENO, "$ ", 2);
		signal(SIGINT, sighand);
		read = getline(&buff, &size, stdin);
		line_counter++;
		if (read == -1)
		{
			if (isatty(0))
				write(STDIN_FILENO, "\n", 1);
			free(buff);
			return (0);
		}
		if (read == 0)
		{
			if (isatty(0))
			{
				write(STDIN_FILENO, "\n", 1);
				continue;
			}
		}
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
			/* checks if 'env', 'exit', or '.' is entered */
			result = str_comp(arr, tok_size);
			if (result == 0)
			{
				free(arr);
				free(buff);
				exit(ex_flag);
			}
			ex_flag = 0;
			if (result == 2)
			{
				free(arr);
				free(buff);
				continue;
			}
			else if (result == 1)
			{
				print_env();
				free(arr);
				free(buff);
				continue;
			}
			/* send input to path function to check */
			/*if it exists, permissions, and if it can execute */
			ex_flag = path(arr, line_counter);
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
