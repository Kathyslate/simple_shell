#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * setenv_builtin - Entry point
 * @name: argument count
 * @value: arguments
 * @overwrite: overwrite value
 *
 * Return: always return 0
 */

int setenv_builtin(const char *name, const char *value, int overwrite)
{
	if (setenv(name, value, overwrite) != 0)
	{
		perror("Error executing command");
		return (1);
	}
	return (0);
}

/**
 * set - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: always return 0
 */

int set(int argc, char *argv[])
{
	int overwrite = atoi(argv[3]);

	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s <name> <value> <overwrite>\n", argv[0]);
		return (1);
	}

	if (setenv_builtin(argv[1], argv[2], overwrite) != 0)
	{
		return (1);
	}

	printf("Environment variable '%s' has been set to '%s'.\n", argv[1], argv[2]);
	return (0);
}


/**
 * unsetenv_builtin - Entry point
 * @name: argument count
 *
 * Return: always return 0
 */

int unsetenv_builtin(const char *name)
{
	if (unsetenv(name) != 0)
	{
		perror("Error executing command");
		return (1);
	}
	return (0);
}

/**
 * unset - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: always return 0
 */

int unset(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <name>\n", argv[0]);
		return (1);
	}

	if (unsetenv_builtin(argv[1]) != 0)
	{
		return (1);
	}

	printf("Environment variable '%s' has been unset.\n", argv[1]);
	return (0);
}
