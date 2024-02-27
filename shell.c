#include "shell.h"

/**
 * main - Shell entry point
 * Return: 0 on success
 */
int main(void)
{
	char **tokens;
	int i;
	pid_t child_pid;

	while (true)
	{
		print("hsh$ ");
		fflush(stdout);

		tokens = process_cmd();

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

		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		free(tokens);

	}

	return (0);
}
