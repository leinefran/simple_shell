#include "shell.h"

/**
 * stringdup - function to return pointer to string (duplicate string)
 * @str: string to duplicate
 * Return: pointer to string or NULL if failure to allocate
 */
char *stringdup(const char *str)
{
	int i, j;

	char *ptr;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	;

	ptr = malloc(sizeof(char) * (i + 1));

	if (!ptr)
		return (NULL);

	for (j = 0; j < i; j++)
		ptr[j] = str[j];

	return (ptr);
}
