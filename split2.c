#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
        char *token, **arr, *str2, *buff;
        int i = 0, count = 0;
        size_t size = 1024, read_chars;

	buff = malloc(sizeof(char*) * size);

	if (!buff)
		return (-1);

	write(1, "$ ", 2);

	read_chars = getline(&buff, &size, stdin);

	if (read_chars == -1)
	{
		free(buff);
		return (-1);
	}

	str2 = strdup(buff);

	if (str2 == NULL)
	{
		free(buff);
		return (-1);
	}

	token = strtok(buff, " ");

	while(token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	arr = malloc(sizeof(char) * (count + 1));

	if (!arr)
	{
		free(buff);
		free(str2);
		return (-1);
	}
	arr[count] = NULL;

	token = strtok(str2, " ");

	while (token != NULL)
	{
		arr[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	i = 0;

	while (arr[i] != '\0')
	{
		printf("%s\n", arr[i]);
		i++;
	}

	free(buff);
	free(str2);

/*      i = 0;

        while (arr[i] != '\0')
        {
                free(arr[i]);
                i++;
        }
*/
	return (0);
}
