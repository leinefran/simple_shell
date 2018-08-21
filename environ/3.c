#include <stdio.h>

char *_getenv(const char *name)
{
	extern char** environ;

	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}

