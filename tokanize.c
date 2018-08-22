#include "shell.h"

char **tokanize (char *str, char **arr)
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
