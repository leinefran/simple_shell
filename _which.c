#include "shell.h"

/**
 * _which - This function checks whether a file exists in PATH
 * @file: The file to check
 * Return: On success, 0. Otherwise, -1.
 */

int _which(char *file)
{
	struct stat status;

	while (file)
	{
		if (stat(file, &status) == 0)
		{
			return (0);
		}
		break;
	}
	return (-1);
}
