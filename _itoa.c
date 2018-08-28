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
