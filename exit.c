/*
 * File - test.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - handle arguments for the built-in exit
 * Usage: exit status, where status is an integer used to exit the shell
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_NUM_ARGUMENTS 100
#define MAX_COMMAND_LENGTH 1000

/**
 * execute_command - executes command from standard input
 * @argv: argument vector
 * Return: always returns 0
 */

int execute_command(char **argv)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return (1);
	}
	else if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("Command execution failed");
			exit(1);
		}
	}
	else
	{
		while (waitpid(pid, &status, 0) == -1)
		{
			if (errno != EINTR)
			{
				perror("Waitpid failed");
				return (1);
			}
		}
		return (WEXITSTATUS(status));
	}
	return (0);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: always return 0
 */

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_NUM_ARGUMENTS];
	int num_arguments = 0;
	char *token;


	while (1)
	{
		printf("megnix: ");
		fflush(stdout);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			break;
		}

		token = strtok(command, " \t\r\n");
		while (token != NULL)
		{
			arguments[num_arguments++] = token;
			token = strtok(NULL, " \t\r\n");
		}
		arguments[num_arguments] = NULL;


		int status = execute_command(arguments);

		if (status == 1)
		{
			perror("Error executing command");
		}

		num_arguments = 0;
	}

	return (0);
}
