#include "shell.h"

/**
 * toksize - number of tokens from getline
 * @str: string to count number of tokens
 * Return: number of tokens
 */
int toksize (char *str)
{
	int tok_size = 0;

	char *token = NULL;

	token = strtok(str, " ");

	if (token == NULL)
	{
		write(STDIN_FILENO, '\0', 1);
		return(-1);
	}
	while (token != NULL)
	{
		tok_size++;
		token = strtok(NULL, " ");
	}
	return (tok_size);
}
