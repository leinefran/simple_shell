#include "shell.h"
/**
 * _itoa - converts int to string
 * @n: integer given
 * Return: new string
 */

char *_itoa(int n)
{

	long x;
	int count, adjust;
	char *string;

	/* creating space for max/min int character string */
	string = malloc(sizeof(char) * 12);
	/* if string passed is NULL, return NULL */
	if (string == NULL)
		return (NULL);

	/* cast the passed integer n into a long variable */
	x = n;

	/* initialize count to zero */
	count = 0;

	/* if x is a negative number */
	if (x < 0)
	{
		/* append the negative sign */
		string[count++] = '-';
		/* convert the number to a positive number */
		x = x * -1;
	}

	/* if x is greater than 9 */
	if (x > 9)
	{
		adjust = 10;

		/* if x is > 10, parse through to get to highest place */
		while (x / adjust >= 10)
			adjust = adjust * 10;

		/* append the converted highest's place int into the string */
		string[count++] = ((x / adjust) + '0');

		/* if x is greater than or equal to 10 */
		while (adjust >= 10)
		{
			/* move backward through number */
			adjust = adjust / 10;
			/* append converted numbers into the string */
			string[count++] = (((x / adjust) % 10)  + '0');
		}

	}
	/* else if x is a single digit, convert and append to string */
	else
		string[count++] = x + '0';

	/* append null */
	string[count] = 0;
	return (string);
}
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
	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line_counter, _strlen(line_counter));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));

	if (flag == 0)
		write(STDERR_FILENO, ": not found\n", 13);
	else if (flag == 1)
		perror(" ");

	free(line_counter);
}
/**
 * get_pid - function to get process ID of the calling process
 * Return: pid;
 */
unsigned int get_pid(void)
{
	unsigned int pid;

	pid = getpid();
	return (pid);
}
/**
 * get_ppid - function to return the process ID of the
 * parent process of the calling process
 * Return: ppid
 */
unsigned int get_ppid(void)
{
	unsigned int ppid;

	ppid = getppid();
	return (ppid);
}
