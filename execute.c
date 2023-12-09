#include "shell.h"

#define MAXLINE 1024

/**
 * exit_shell - exits the shell
 * @status_code: status of shell
 *
 */

void exit_shell(int status_code)
{
	exit(status_code);
}

/**
 * execute_exit_command - executes command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
 */

void execute_exit_command(char *command)
{
	int status_code;

	if (sscanf(command, "exit %d", &status_code) == 1)
	{
		exit_shell(status_code);
	}
	else
	{
		exit_shell(0);
	}
}


/**
 * execute_command - executes command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
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
