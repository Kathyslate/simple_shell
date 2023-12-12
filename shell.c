#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"


/**
 * main - Entry point
 * Return: always return 0
 */

int main(void)
{
	char command[MAX_LINE_LENGTH];


	while (1)
	{
		printf("megnix> ");
		fflush(stdout);
		read_command(command);

		if (strncmp(command, "exit", 4) == 0)
		{
			execute_exit_command(command);
			break;
		}
			if (execute_command(command) != 0)
			{
				break;
			}
	}

	return (0);
}



/**
 * execute_command - executes command from standard input
 * @argv: arguments
 * Return: always return 0
 */

int execute_command(char *command)
{
	char *argv[MAX_LINE_LENGTH / 2 + 1];
	char *token = strtok(command, " ");
	int status;
	int i = 0;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return (1);
	}
	if (pid == 0)
	{
		while (token != NULL)
		{
			argv[i++] = token;
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;

		if (execvp(argv[0], argv) == -1)
		{    
			perror("Error executing command");
			exit(1);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error waiting for child process");
			return (1);
		}
	}

	return (0);
}
/**
 * find_command - executes command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
 */

void find_command(char *command)
{
	char *path;
	char *path_ptr;
	char *cmd_ptr;
	char *pathvar;
	char cmd_path[1024];

	pathvar = getenv("PATH");

	if (!pathvar)
	{
		printf("The PATH environment variable is not set.\n");
		return;
	}

	path = strdup(pathvar);
	path_ptr = strtok(path, ":");

	while (path_ptr)
	{
		cmd_ptr = strtok(NULL, ":");
		strcpy(cmd_path, path_ptr);
		strcat(cmd_path, "/");
		strcat(cmd_path, command);

		if (is_executable(cmd_path))
		{
			printf("The command '%s' exists at: %s\n", command, cmd_path);
			return;
		}

		path_ptr = cmd_ptr;
	}

	printf("The command '%s' does not exist.\n", command);
}
