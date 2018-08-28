#include "shell.h"

/**
 * error - This function returns custom error messages
 * @str: The argument at index 0
 * @line: Line count from getline function
 * @flag: To determine which error message to output
 */

void error(char *str, int line, int flag)
{
	char *line_counter = _itoa(line);
	char *shell = _getenv("_");
	char *error_msg = str_concat(shell, ": ", flag);

	/* concatenate error message */
	error_msg = str_concat(error_msg, line_counter, flag);
	error_msg = str_concat(error_msg, ": ", flag);
	error_msg = str_concat(error_msg, str, flag);

	/* error message dependent on situation */
	if (flag == 2) /* permission denied */
		error_msg = str_concat(error_msg,
": Permission denied\n", flag);
	else if (flag == 0) /* fie not found */
		error_msg = str_concat(error_msg, ": not found\n", flag);
	else /* malloc error */
		error_msg = str_concat(error_msg, " : TEST\n", flag);

	write(1, error_msg, _strlen(error_msg));

	free(error_msg);
}
