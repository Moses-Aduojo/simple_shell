#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

char **process_cmd(void);
int print(char *str);
char *get_cmd(void);
void exec_cmd(char **tokens);

#endif /*SHELL_H*/
