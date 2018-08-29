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
