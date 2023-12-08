#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_NUM_ARGUMENTS 100
#define MAX_COMMAND_LENGTH 1000

int execute_command(char *command)
{
	char *args[MAX_NUM_ARGUMENTS];
	int argc = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[argc++] = token;
		token = strtok(NULL, " ");
	}
	args[argc] = NULL;

	pid_t pid = fork();
	
	if (pid == -1)
	{
		perror("Fork failed");
		return 1;
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Command execution failed");
			exit(1);
		}
	}
	else
	{
		int status;
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Waitpid failed");
			return 1;
		}
		return WEXITSTATUS(status);
	}
return (0);
}

int main(int argc, char *argv[])
{    
	while (1)
	{
		printf("megnix: ");
		fflush(stdout);

		char* command = (char*) malloc(MAX_COMMAND_LENGTH * sizeof(char));
		fgets(command, MAX_COMMAND_LENGTH, stdin);

		if (strncmp(command, "exit", 4) == 0)
		{
			free(command);
			exit(0);
		}
		int status_code;
		if (sscanf(command, "exit %d", &status_code) == 1) {
			free(command);
			exit(status_code);
		}
		else (execute_command(command) != 0);
		{
			printf("Error: execute_command function failed\n");
		}

		free(command);
	}

	return 0;
}
