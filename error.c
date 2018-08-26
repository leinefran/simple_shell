#include "shell.h"

/**
 * error - This function returns custom error messages
 * @str - The argument at index 0
 */

void error(char *str)
{
        char *shell = _getenv("_");
        printf("%s: 1: %s: not found\n", shell, str);
}
