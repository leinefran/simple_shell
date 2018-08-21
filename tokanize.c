#include "shell.h"

char **tokanize (char *str, char **arr)
{
	char *tokan;
	int i = 0;

	tokan = strtok(str, " \n");

	while (tokan != NULL)
	{
		arr[i] = tokan;
		printf("arr[i] = arr[%s]\n", arr[i]);
		tokan = strtok(NULL, " \n");
		i++;
	}
	return (arr);
}
