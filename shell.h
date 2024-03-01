#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_TOKENS 180
void process_cmd(char *line_buff, char *str, char **environ);
int print(char *str);
ssize_t get_cmd(char **line_buff, size_t *line_buf_size);
void get_cmd_tokens(char *line_buff, char **exec_args);
void exec_cmd(char **exec_args, char *str, char **environ);

#endif /*SHELL_H*/
