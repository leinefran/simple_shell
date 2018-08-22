#include "shell.h"

/**
 * exit_shell - function to exit shell if string compare returns 0
 * @arr: array of string pointers
 * @tok_num: size of array
 * Return: 0 or -1
 */
int exit_shell(char **arr, int tok_num)
{
	int result = 0;

	if (tok_num != 1)
		return (-1);
	result = str_comp(arr);
	return (result);
}
