#include <stdio.h>

int main(int ac, char **av, char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}

	return (0);

}
