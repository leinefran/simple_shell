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

	while (ex[i] != '\0' && ptr[i] != '\0')
	{
		if (ex[i] != ptr[i])
			return (-1);
		i++;
	}
	return (0);
}
