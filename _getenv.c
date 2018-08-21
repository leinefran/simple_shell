#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _getenv - a function that gets an environment variable.
 * (without using getenv)
 * @name: the variable to be compared with environ.
 * Return: char.
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i, j, length = 0;

	while (name[length] != '\0')
		length++;

	if (length == 0)
		return (NULL);

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		for(j = 0 ; name[j] != '\0' ; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (name[j] == '\0')
			return (environ[i] + j + 1);
	}
	return (NULL);
}
