#include "shell.h"
/**
 * get_ppid - function to return the process ID of the 
 * parent process of the calling process
 * Return: ppid
 */
unsigned int get_ppid()
{
	unsigned int ppid;
	ppid = getppid();
	return (ppid);
}
