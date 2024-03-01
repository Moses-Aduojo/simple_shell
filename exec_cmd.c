#include "shell.h"

/*extern char **environ;*/
/**
 * exec_cmd - execute other program pass to it as command
 * @exec_args: pointer to array of command and its argument
 * Return: void
 */
void exec_cmd(char **exec_args, char *str, char **environ)
{
	if (execve(exec_args[0], exec_args, environ) == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}
