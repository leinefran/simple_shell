#include "shell.h"

/**
 * stringdup - function to return pointer to string (duplicate string)
 * @str: string to duplicate
 * Return: pointer to string or NULL if failure to allocate
 */
char *stringdup(const char *str)
{
	int i, j;

	char *ptr;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	;

	ptr = malloc(sizeof(char) * (i + 1));

	if (!ptr)
		return (NULL);

	for (j = 0; j < i; j++)
		ptr[j] = str[j];

	return (ptr);
}
/**
 * _strlen - This function returns the length of a string
 * @s: Variable that contains a character array to be counted
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		continue;

	return (i);
}
/**
 * str_comp - compare two strings
 * @arr: array of string pointers
 * @size: size of the array
 * Return: 0 on success, -1 on failure
 */
int str_comp(char **arr, int size)
{
	char *command[4] = {"exit", "env", ".", NULL};
	char *ptr = arr[0];

	int i = 0, j = 0, flag = 0;

	if (size != 1)
		return (-1);

	if (!ptr)
		return (1);

	while (command[i] != NULL)
	{
		j = 0;
		while (command[i][j] == ptr[j])
		{
			if (command[i][j] == '\0' || ptr[j] == '\0')
				break;
			j++;
		}
		if (command[i][j] == ptr[j])
			return(flag);
		i++;
		flag++;
	}

	return (-1);
}
/**
 * str_concat - concatenates two strings
 * The returned pointer points to a newly allocated space in memory
 * which contains the contents.
 *
 * @s1: string to be modified.
 * @s2: string to be appended.
 * @flag: integer flag for handling path or error function
 * ls: linked_string (after concatenate).
 *
 * Return: char.
 */
char *str_concat(char *s1, char *s2, int flag)
{
	int len1 = 0, len2 = 0, i, j;

	char *ptr;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		*s2 = '\0';
	}
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	ptr = malloc(sizeof(char) * (len1 + len2 + 1 + flag));
	if (ptr == NULL)
		return (NULL);
	for (i = 0 ; s1[i] != '\0' ; i++)
		ptr[i] = s1[i];
	if (flag == 1)
	{
		ptr[i] = '/';
		i++;
	}
	for (j = 0 ; j < (len2 + 1) ; j++, i++)
		ptr[i] = s2[j];
	return (ptr);
}
