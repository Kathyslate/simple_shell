#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024
#define MAX_LINE_LENGTH 80

void simple_shell();
int main(void);
void read_command(char *command);
int execute_command(char *command);

#endif
