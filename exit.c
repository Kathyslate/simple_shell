/*
 * File - test.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - handle arguments for the built-in exit
 * Usage: exit status, where status is an integer used to exit the shell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGUMENTS 64

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: always return 0
 */

int main(int argc, char *argv[])
{
	char *command;
	char *arguments[MAX_NUM_ARGUMENTS];
	int status;

	while (1)
	{
		printf("megnix: ");
		fflush(stdout);


		command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
		fgets(command, MAX_COMMAND_LENGTH, stdin);

		if (strncmp(command, "exit", 4) == 0)
		{
			int status_code;

			if (sscanf(command, "exit %d", &status_code) == 1)
			{
				free(command);
				exit(status_code);
			} else
			{
				free(command);
				exit(0);
			}
		}

		char *token = strtok(command, " \n");
		int i = 0;

		while (token != NULL && i < MAX_NUM_ARGUMENTS)
		{
			arguments[i++] = token;
			token = strtok(NULL, " \n");
		}
		arguments[i] = NULL;


		pid_t pid = fork();

		if (pid == 0)
		{
			execvp(arguments[0], arguments);
			printf("Command not found: %s\n", arguments[0]);
			exit(0);
		} else if (pid < 0)
		{
			printf("Fork failed\n");
		} else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}

		free(command);
	}

	return (0);
}
