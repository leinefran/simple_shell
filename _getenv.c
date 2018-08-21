#include <stdio.h>
#include <stdlib.h>
char *_getenv(const char *name);
void main(int argc, char *argv[], char * envp[])
{
	printf("PATH: %s\n", _getenv("PATH"));
	printf("HOME: %s\n", _getenv("HOME"));
	printf("ROOT: %s\n", _getenv("ROOT"));

}
char *_getenv(const char *name)
{
	char *envp;
	int i, j, found = 0, length = 0;

	while (name[length] != '\0')
		length++;

	if (length == 0)
		return (NULL);

	for (i = 0 ; envp[i] != '\0' ; i++)
	{
		for (j = 0 ; name[j] != '\0' ; j++)
		{
			if (envp[i + j] != name[j])
			{
				found = 0;
				break;
			}
			else
			{
				found = 1;
			}
		}
		if (found == 1)
			return (envp + i);
	}
	return (envp + i);
}
