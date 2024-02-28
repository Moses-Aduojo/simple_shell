#include "shell.h"

/**
 * main - Shell entry point
 * Return: 0 on success
 */
int main(void)
{
	char *line_buff = NULL;
	size_t line_buff_size = 0;
	ssize_t n_read;

	while (true)
	{
		print("$ ");
		fflush(stdout);

		n_read = get_cmd(&line_buff, &line_buff_size);

		line_buff[n_read - 1] = '\0';

		process_cmd(line_buff);
	}
	free(line_buff);
	return (0);
}
