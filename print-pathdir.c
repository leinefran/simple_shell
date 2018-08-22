#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print-pathdir - a function that prints each directory contained in the
 * the environment variable PATH, one directory per line.
 * @name: the variable to be compared with environ.
 * Return: char.
 */
char *_getenv(const char *name);
void print_pathdir(char *name)
{
	char *str = _getenv(name);
	char *token;

	token = strtok(str, ":");


	while (token != NULL)
	{
		write(1, token, strlen(token));
		token = strtok(NULL, ":");
		putchar('\n');
	}
}
/**
 * _getenv - a function that gets an environment variable.
 * (without using getenv)
 * @name: the variable to be compared with environ.
 * Return: char.
 */
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
void main()
{
	char *name = "PATH";

	print_pathdir(name);
}
