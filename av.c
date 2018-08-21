#include <stdio.h>

int main(int ac, char **av)
{
	(void) ac;
	int i = 0;

	while (av[i] != '\0')
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
