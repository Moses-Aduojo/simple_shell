#include "shell.h"

/**
 * process_cmd - get and parse command from command line
 * Return: pointer to an array of the command tokens processed
 */
void process_cmd(char *line_buff, char *str, char **environ)
{
	char *exec_args[MAX_TOKENS];
	int status;

	pid_t pid;

	get_cmd_tokens(line_buff, exec_args);
	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		exec_cmd(exec_args, str, environ);
	}
	else
		waitpid(pid, &status, 0);

}
