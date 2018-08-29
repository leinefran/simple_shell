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
		/* check if first index is a tab */
		if (str[i] == '\t')
			str[i] = ' ';
		/* check if next index is a tab */
		if (str[i + 1] == '\t')
			str[i + 1] = ' ';
		/**
		 * if idx is not a space (it's a char)
		 * AND the idx after is either space or null,
		 * (meaning end of a word) count it as a token
		 */
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			tok_size++;
		i++;
	}
	return (tok_size);
}
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
