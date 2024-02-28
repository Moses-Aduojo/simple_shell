#include "shell.h"

/**
 * get_cmd_tokens - tokenize comget_cmd_tokens
 * @line: pointer to command string
 * @exec_args: store argument tokens
 * Return: void
 */
void get_cmd_tokens(char *line, char **exec_args)
{
	char *token;
	int i = 0;

	token = strtok(line, " ");
	while (token != NULL && i < MAX_TOKENS - 1)
	{
		exec_args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	exec_args[i] = NULL;
}
