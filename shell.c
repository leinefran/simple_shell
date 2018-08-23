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
	int ex, tok_size = 0, len = 0;
	pid_t c_pid = 0;

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

			len = strlen(str);
			if (str[len - 1] == '\n')
				str[len - 1] = '\0';

			arr = tokanize(str, arr);

			ex = exit_shell(arr, tok_size);

			if (ex == 0)
				exit(0);
			if (ex == 1)
				continue;

			few(c_pid, arr);
		}

		if (buff && buff[0] == '\n')
			continue;

		free(arr);
		free(str);
	}
	return (0);
}
