#include "shell.h"
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
