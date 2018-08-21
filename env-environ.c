#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv, char **envp)
{
	int i = 0;
	extern char **environ;

/* The addresses are different */

//prints the address of env:
	printf("Address of env: %p\n", envp);
	printf("\n");

//prints the address of environ:
	printf("Address of environ: %p\n", *environ);
        printf("\n");

/* This part isn't really necessary. I added just to compare the results, which
   are the same, although one loop uses envp and the other uses environ */

//print the environment using parameter envp:
	printf("I am the result of  envp, the 3rd parameter\n");
	printf("\n");
	while(*envp != NULL)
	{
		printf("%s\n", *envp);
		envp++;
	}
	printf("\n");

//print the environment using global variable environ:
	printf("I am the global variable environ\n");
	printf("\n");
	while(environ[i])
	{
		printf("%s\n", environ[i++]); // form of "variable=value"
	}
	return 0;
}
