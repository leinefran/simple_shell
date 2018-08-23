#include "shell.h"
/**
 * main - simple shell program
 * Return: 0 always success
 */
int main(void)
{
	/*unsigned int pid, ppid;*/
	ssize_t read = 0;
	char *buff = NULL, *str = NULL, **arr;
	size_t size = 0;
<<<<<<< HEAD
	int tok_size = 0, result = 0;
	pid_t c_pid;
=======
	int ex, tok_size = 0;
	pid_t c_pid = 0;
>>>>>>> 1d1c86171bad59db14b4a2056d290033ee4b279b

	/*pid = get_pid();*/
	/*ppid = get_ppid();*/
	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		read = getline(&buff, &size, stdin);
		if (read == -1)
		{
			free(buff);
			return (-1);
		}
<<<<<<< HEAD
		printf("read = %li\n", read);
=======
>>>>>>> 1d1c86171bad59db14b4a2056d290033ee4b279b
		if (buff && buff[0] != '\n')
		{
			str = stringdup(buff);
			tok_size = toksize(buff);
			if (tok_size == -1)
				break;
			arr = malloc(sizeof(char *) * (tok_size + 1));
			if (!arr)
				return (-1);
			arr[tok_size] = NULL;

			arr = tokanize(str, arr);
<<<<<<< HEAD
			printf("arr = %s\n", *arr);

			result = few(c_pid, arr);
=======

			ex = exit_shell(arr, tok_size);

			if (ex == 0)
				exit(0);

			few(c_pid, arr);
>>>>>>> 1d1c86171bad59db14b4a2056d290033ee4b279b
		}
		free(arr);
		free(str);
	}
	return (0);
}
