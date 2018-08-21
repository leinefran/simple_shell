#include <stdio.h>

extern char** environ;

int main(int ac, char **av)
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
