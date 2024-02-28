#include "shell.h"

/**
 * exec_cmd - execute other program pass to it as command
 * @exec_args: pointer to array of command and its argument
 * Return: void
 */
void exec_cmd(char **exec_args)
{
	if (execve(exec_args[0], exec_args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
