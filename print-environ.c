#include <unistd.h>
#include <stdio.h>

int main()
{
	int i = 0;
	extern char **environ;
	while(environ[i])
	{
		// prints in form of "variable=value"
		printf("%s\n", environ[i++]);
	}
}
