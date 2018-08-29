#include "shell.h"

/**
 * error - This function returns custom error messages
 * @str: The argument at index 0
 * @line: Line count from getline function
 * @flag: To determine which error message to output
 */

void error(char *str, int line, int flag)
{
	char *line_counter = NULL;
	char *shell = _getenv("_");

	line_counter = _itoa(line);
	write(1, shell, _strlen(shell));
	write(1, ": ", 2);
	write(1, line_counter, _strlen(line_counter));
	write(1, ": ", 2);
	write(1, str, _strlen(str));

	if (flag == 0)
		write(1, ": file not found\n", 18);
	else if (flag == 1)
		perror(" ");

	free(line_counter);
}
