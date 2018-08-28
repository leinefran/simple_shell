#include "shell.h"

/**
 * str_comp - compare two strings
 * @arr: array of string pointers
 * @size: size of the array
 * Return: 0 on success, -1 on failure
 */
int str_comp(char **arr, int size)
{
	char *ex = "exit", *env = "env", *ptr = arr[0];
	char *dot = ".";

	int i = 0;

	if (size != 1)
		return (-1);

	if (!ptr)
		return (1);

	while (ex[i] == ptr[i] || env[i] == ptr[i] || dot[i] == ptr[i])
	{
		if (ex[i] == '\0' && ptr[i] == '\0')
			return (0);
		else if (dot[i] == '\0' && ptr[i] == '\0')
			return (2);
		else if (env[i] == '\0' && ptr[i] == '\0')
		{
			print_env();
			return (1);
		}

		i++;
	}

	return (-1);
}
