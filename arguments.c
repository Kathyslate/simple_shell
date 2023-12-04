#include "shell.h"

#define MAX_LINE_LENGTH 80

void read_command(char *command)
{
	char c;
	int i = 0;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		command[i++] = c;
	}
	command[i] = '\0';
}

int execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return (1);
	}

	if (pid == 0)
	{
		char *args[MAX_LINE_LENGTH / 2 + 1];
		char *token = strtok(command, " ");
		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (execvp(args[0], args) == -1)
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

int main(void)
{
	char command[MAX_LINE_LENGTH];

	while (1)
	{
		printf("megnix> ");
		fflush(stdout);
		read_command(command);

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		if (execute_command(command) != 0)
		{
			break;
		}
	}
	return (0);
}
