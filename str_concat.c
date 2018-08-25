#include "shell.h"

/**
 * str_concat - concatenates two strings
 * The returned pointer points to a newly allocated space in memory
 * which contains the contents.
 *
 * @s1: string to be modified.
 * @s2: string to be appended.
 * ls: linked_string (after concatenate).
 *
 * Return: char.
 */
char *str_concat(char *s1, char *s2)
{
	int s1_len;
	int s2_len;

	int i, j, n;
	char *ls;

	for (s1_len = 0 ; s1[s1_len] != '\0' ; s1_len++)
		;
	for (s2_len = 0 ; s2[s2_len] != '\0' ; s2_len++)
		;

	n = s1_len + s2_len + 2;

	if (s1 == NULL)
		s1[0] = '\0';
	if (s2 == NULL)
		s2[0] = '\0';


	ls = malloc(sizeof(char) * n);

	if (ls == NULL)
		return (NULL);

	for (i = 0 ; s1[i] != '\0' ; i++)
		ls[i] = s1[i];
	ls[i] = '/';
	i++;
	for (j = 0 ; s2[j] != '\0' ; j++)
		ls[i + j] = s2[j];


	return (ls);
}
