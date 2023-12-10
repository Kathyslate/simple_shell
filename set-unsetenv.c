#include "shell.h"

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
