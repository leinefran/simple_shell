#include "shell.h"

/**
 * tokenize - function to get tokens from string
 * and store in an array
 * @str: string to tokenize
 * Return: array
 */
char **tokenize(char *str)
{
	char *token, **arr;
	int i = 0, words;

	words = toksize(str);
	if (!words)
		return (NULL);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	token = strtok(str, " \t");
	while (token != NULL)
	{
		arr[i] = token;
		token = strtok(NULL, " \t");
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
