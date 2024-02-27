#include "shell.h"

/**
 * get_cmd - get user commands and command args from command line
 * Return: pointer to the comand string
 */
char *get_cmd(void)
{
	char *buff = NULL;
	size_t buff_size = 0;
	ssize_t n_read;

	n_read = getline(&buff, &buff_size, stdin);

	if (n_read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (buff);
}
