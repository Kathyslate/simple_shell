/*
 * File - env.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - A command line interpreter that
 * accepts command from the standard input,handles arguments,
 * handles PATH and doesnt fork incorrect command
 * that has env built-in
 */

#include "shell.h"

/**
 * is_executable - reads command from standard input
 * @filename: command arguments
 *
 * Return: always returns 0
 */

int is_executable(char *filename)
{
	if (access(filename, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * read_command - reads command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
 */

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

/**
 * find_command - finds command from standard input
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

/**
 * execute_command - executes command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
 */

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

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always returns 0
 */

int main(int argc, char *argv[])
{
	char command[MAX_LINE_LENGTH];
	char **env_var;


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

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		printf("%s\n", *env_var);
	}

	if (argc < 2)
	{
		printf("Usage: %s <command>\n", argv[0]);
		exit(1);
	}

	find_command(argv[1]);
	return (0);
}
