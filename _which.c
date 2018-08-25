#include "shell.h"

/**
 * _which - This function checks whether a file exists in PATH
 * @file: The file to check
 * Returns: On success, 0. Otherwise, -1.
 */

int _which(char *file)
{
	unsigned int i = 0;
	struct stat status;

	while(file)
	{
		if (stat(file, &status) == 0)
		{
			return (0);
		}
		else
		{
			return (-1);
		}
	}
	return (1);
}
