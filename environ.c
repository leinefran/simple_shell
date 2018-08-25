#include "shell.h"

/**
 * print_env - a function that prints the environment.
 * Return: 0.
 */

int print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		/* prints in form of "variable=value" */
		write(1, environ[i], _strlen(environ[i]));
		i++;
		write(1, "\n", 1);
	}
	return (0);
}

