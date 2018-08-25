#include "shell.h"

/**
 * print_env - a function that prints the environment.
 */

void print_env(void)
{
	int i, j, length;

	while (environ[i])
	{
		/* prints in form of "variable=value" */
		write(1, environ[i], _strlen(environ[i]);
		i++;
		write(1, "\n", 1);
	}
}

