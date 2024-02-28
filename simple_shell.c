#include "shell.h"

/**
 * main - Shell entry point
 * Return: 0 on success
 */
int main(void)
{
	char **tokens;
	int i;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			print("$ ");

		fflush(stdout);

		tokens = process_cmd();

		if (strcmp(tokens[0], "exit") == 0)
		{
			for (i = 0; tokens[i] != NULL; i++)
				free(tokens[i]);
			free(tokens);

			break;
		}

		exec_cmd(tokens);

		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		free(tokens);

	}

	return (0);
}
