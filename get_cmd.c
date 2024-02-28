#include "shell.h"

/**
 * get_cmd - get user commands and command args from command line
 * @line_buff: poiter to buffer into which line is read
 * @line_buff_size: pointer to variable for storing byte read
 * Return: pointer to the comand string
 */
ssize_t get_cmd(char **line_buff, size_t *line_buff_size)
{
	ssize_t n_read;

	n_read = getline(line_buff, line_buff_size, stdin);

	if (n_read == -1 && feof(stdin))
	{
		print("\n");
		exit(EXIT_SUCCESS);
	}
	else if (n_read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (n_read);
}
