#include "shell.h"

/**
 * toksize - number of tokens from getline
 * @str: string to count number of tokens
 * Return: number of tokens
 */
int toksize(char *str)
{
	int tok_size = 0, i = 0;

	if (!str)
	{
		write(STDIN_FILENO, '\0', 1);
		return (-1);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		if (str[i + 1] == '\t')
			str[i + 1] = ' ';
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			tok_size++;
		i++;
	}
	return (tok_size);
}
