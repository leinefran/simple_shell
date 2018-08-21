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
	extern char **environ;
	int i, j, length = 0;

	while (name[length] != '\0')
		length++;

	if (length == 0)
		return (NULL);

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		for(j = 0 ; name[j] != '\0' ; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (name[j] == '\0')
			return (environ[i] + j + 1);
	}
	return (NULL);
}
