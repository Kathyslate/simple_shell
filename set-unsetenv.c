#include "shell.h"
/**
 * split_command -  Function to split the command into words
 * @command: commands
 * @argc: argument count
 *
 * Return: argv
 */

char **split_command(char *command, int *argc)
{
	char **argv = malloc(100 * sizeof(char *));
	char *token = strtok(command, " ");
	*argc = 0;

	while (token != NULL)
	{
		argv[*argc] = token;
		(*argc)++;
		token = strtok(NULL, " ");
	}

	return (argv);
}

/**
 * handle_setenv - handles environment inbuilt
 * @tokens: takes in token
 *
 * Return: always returns 0
 */
void handle_setenv(char **tokens)
{
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		fprintf(stderr, "setenv: not enough arguments\n");
		return;
	}
	if (setenv(tokens[1], tokens[2], 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * handle_unsetenv - handles environment inbuilt
 * @tokens: takes in token
 *
 * Return: always returns 0
 */

void handle_unsetenv(char **tokens)
{
	if (tokens[1] == NULL)
	{
		fprintf(stderr, "unsetenv: not enough arguments\n");
		return;
	}

	if (unsetenv(tokens[1]) != 0)
	{
		perror("unsetenv");
	}
}
