#include "shell.h"

/**
 * str_comp - compare two strings
 * @arr: array of string pointers
 * Return: 0 on success, -1 on failure
 */
int str_comp(char **arr)
{
	char *ex = "exit", *ptr = arr[0];

	int i = 0;

	if (!ptr)
		return (1);

	while (ex[i] == ptr[i])
	{
		if (ex[i] == '\0' && ptr[i] == '\0')
			return (0);

		i++;
	}

	return (-1);
}
