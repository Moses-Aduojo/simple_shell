#include "shell.h"
#define MAX_TOKENS 180

/**
 * process_cmd - get and parse command from command line
 * Return: pointer to an array of the command tokens processed
 */
char **process_cmd(void)
{
	char *buff = NULL;
	char **tokens = NULL;
	char *token = NULL;
	int i, j;

	buff = get_cmd();

	tokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(buff, " \t\n");
	i = 0;
	while (token != NULL && i < MAX_TOKENS - 1)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			perror("strdup");
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			free(buff);
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	free(buff);
	return (tokens);
}
