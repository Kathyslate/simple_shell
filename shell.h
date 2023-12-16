#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE


#include <signal.h>
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


#define MAX_LINE_LENGTH 80
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

int status;
void simple_shell(void);
int exit1(void);
int setenv_builtin(const char *name, const char *value, int overwrite);
int unsetenv_builtin(const char *name);
int set(int argc, char *argv[]);
int unset(int argc, char *argv[]);
int exit2(void);
void exit_shell(int status_code);
void exit_handler(int signum);
int is_executable(char *filename);
void find_command(char *command);
extern char **environ;
int builtin_cd(char **args);
void env_builtin(int argc);
void execute_command(char *command);
void execute_exit_command(char *command);
void read_command(char *command);
int exiter(void);
char command[MAX_LINE_LENGTH];


int megnix_getline(char buffer[], int max_length);
int my_getline(char buffer[], int max_length);
#endif
