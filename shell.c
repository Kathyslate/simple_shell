#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"


/**
 * execute_command - executes command from standard input
 * @command: arguments
 * Return: always return 0
 */


int execute_command(char *command)
{
	pid_t pid;
	char *argv[100];
	int argc = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}

	argv[argc] = NULL;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			if (errno == ENOENT)
			{
				printf("Command not found.\n");
			} else
			{
				printf("An error occurred.\n");
			}

			exit(1);
		}
	} else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
	} else
	{
		perror("Fork failed");
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
