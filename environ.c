#include "shell.h"

int print_env()
{
	int i, j, length;

	while(environ[i])
	{
		// prints in form of "variable=value"
		write (1, environ[i], _strlen(environ[i]));
		i++;
		write (1, "\n", 1);
	}
}

