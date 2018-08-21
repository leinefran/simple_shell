#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int r;
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = malloc(bufsize * sizeof(char));
	if( buffer == NULL)
		exit(1);

	write(1, "$ ", 2);
	wait(NULL);
	characters = getline(&buffer,&bufsize,stdin);
	if (characters < 0)
		return (-1);
	write(1, buffer, characters);
	free(buffer);
	return (characters);
}
