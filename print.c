#include "shell.h"

/**
 * print - print a given string to std output
 * @str: pointer to the given string
 * Return: numbers of byte written or -1 if error
 */
int print(char *str)
{
	int n;

	n = write(STDOUT_FILENO, str, strlen(str));
	if (n == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	return (n);
}
