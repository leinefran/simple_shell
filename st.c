#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - this program looks for files in the current PATH
 */

int _which(char *file)
{
	unsigned int i = 0;
	struct stat status;

	while(file)
	{
		if (stat(file, &status) == 0)
		{
			printf(" FOUND\n");
			break;
		}
		else
		{
			printf(" NOT FOUND\n");
			break;
		}
	}
	return (0);
}

int main(int ac, char** av)
{
        int status;

	if (ac < 2)
        {
                printf("Usage: %s path_to_file... \n", av[0]);
                return (1);
        }

	status = _which(av[1]);

	printf("%d\n", status);

	return (0);
}
