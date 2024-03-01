#include "shell.h"

/**
 * get_cmd_tokens - tokenize comget_cmd_tokens
 * @line: pointer to command string
 * @exec_args: store argument tokens
 * Return: void
 */
void get_cmd_tokens(char *line_buff, char **exec_args)
{
	char *token;
	int i = 0;
	token = strtok(line_buff, " ");

	while (token != NULL && i <  1024)
	{
	/*	print(token);*/
	/*	print("\n");*/
		exec_args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	exec_args[i] = NULL;


	/*exec_args[0] = line_buff;*/
	/*exec_args[1] = NULL;*/
}
