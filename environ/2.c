#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

int _strcmp(char *s1, char *s2)
{
	int i;

	/* loop through both strings while s1 & s2 are not null */
	for (i = 0; s1[i] != 0 && s2[i] != 0; i++)
	{
		/* find where characters don't match in strings */
		if ((s1[i] - s2[i]) != 0)
			break;
	}

	/* return difference between those characters */
	return (s1[i] - s2[i]);
}

char *_getenv(const char *name)
{
	char *path, *key, **env = environ;

	while (*environ != NULL)
	{
		char *key = strtok(*env, "=");
		char *path = strtok(0, "\n");
		if (_strcmp(key, name) == 0)
			return (path);
		environ++;
	}

}

int main(int ac, char** av)
{
	char *name = "HOME";
	char *value;

	value = _getenv(name);

	printf("%s\n", value);
}
