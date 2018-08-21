#include "shell.h"
/**
 * main - simple shell program
 * Return: 0 always success
 */
int main(void)
{
	unsigned int pid, ppid;
	ssize_t read = 0;
	char *buff = NULL, *str = NULL, **arr;
	size_t size = 0;
	int tok_size = 0;

	pid = get_pid();
	ppid = get_ppid();
	printf("pid = %u\nppid = %u\n", pid, ppid);
	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		read = getline(&buff, &size, stdin);
		if (read == -1)
			return (-1);
		printf("read = %li\n", read);
		if (buff && buff[0] != '\n')
		{
			str = stringdup(buff);
			printf("str = %s", str);
			tok_size = toksize(buff);
			printf("tok_size = %d\n", tok_size);
			if (tok_size == -1)
				break;
			arr = malloc(sizeof(char*) * (tok_size + 1));
			if (!arr)
				return (-1);
			arr[tok_size] = NULL;

			arr = tokanize(str, arr);
			printf("arr = %s\n", *arr);
		}
	}
	return (0);
}
