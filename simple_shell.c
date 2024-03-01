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
	bool prompt;

	if (argc == 0)
		exit(EXIT_FAILURE);
	prompt = true;

	while (prompt)
	{
		do
		{
			if (isatty(STDIN_FILENO))
			{
				print("$ ");
			}
			fflush(stdout);

			n_read = get_cmd(&line_buff, &line_buff_size);
		}while (n_read <= 1 || (line_buff[0] == '\n' && line_buff[1] == '\0'));

		line_buff[n_read - 1] = '\0';
		if (strcmp(line_buff, "exit") == 0)
		{
			break;
		}

		process_cmd(line_buff, argv[0], environ);
	}
	free(line_buff);
	return (0);
}
