#include "shell.h"

/**
 * tokanize - function to get tokans from string
 * and store in an array
 * @str: string to tokanize
 * @arr: array to store tokans
 * Return: array
 */
char **tokanize(char *str, char **arr)
{
	char *tokan;
	int i = 0;

	tokan = strtok(str, " \n");

	while (tokan != NULL)
	{
		arr[i] = tokan;
		tokan = strtok(NULL, " \n");
		i++;
	}
	return (arr);
}
