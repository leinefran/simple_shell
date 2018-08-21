#include <string.h>
#include <stdio.h>

/* a program for splitting a string */

char* split(char *str);
int main()
{
	char str [] = "The gates of shell";
	char *token = split(str);

	while (token != NULL)
	{
		write(1, token, strlen(token));

/* next line sets it back to it's last know position */
		token = strtok(NULL, " ");
		putchar('\n');
	}
	return (0);
}
char* split(char *str)
{
	char *token = strtok(str, " "); //returns first token

	return (token);
}
