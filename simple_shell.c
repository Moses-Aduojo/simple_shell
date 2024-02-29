#include "shell.h"

/**
 * main - Shell entry point
 * Return: 0 on success
 */
int main(int argc, char **argv, char **environ)
{
	char *line_buff = NULL;
	size_t line_buff_size = 0;
	ssize_t n_read;

	if (argc == 0)
		exit(EXIT_FAILURE);

	while (true)
	{
		print("$ ");
		fflush(stdout);

		n_read = get_cmd(&line_buff, &line_buff_size);

		line_buff[n_read - 1] = '\0';

		process_cmd(line_buff, argv[0], environ);
	}
	free(line_buff);
	return (0);
}
