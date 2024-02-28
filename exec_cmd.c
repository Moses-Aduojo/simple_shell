#include "shell.h"

/**
 * exec_cmd - execute other program pass to it as command
 * @str: pointer to array of command and its argument
 * Return: void
 */
void exec_cmd(char **tokens)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(tokens[0], tokens, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
