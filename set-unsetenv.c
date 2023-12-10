#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * setenv_builtin - handles environment inbuilt
 * @argc: takes in name
 * @argv: values in
 *
 * Return: always returns 0
 */

int setenv_builtin(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s VARIABLE VALUE\n", argv[0]);
		return (1);
	}

	if (setenv(argv[1], argv[2], 1) != 0)
	{
		perror("setenv");
		return (1);
	}

	return (0);
}

/**
 * unsetenv_builtin - handles environment inbuilt
 * @argc: takes in name
 * @argv: argument vector
 *
 * Return: always returns 0
 */

int unsetenv_builtin(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s VARIABLE\n", argv[0]);
		return (1);
	}

	if (unsetenv(argv[1]) != 0)
	{
		perror("unsetenv");
		return (1);
	}

	return (0);
}

/**
 * cd- change directory
 * @argc: new directory
 * @argv: argument vector
 *
 * Return: always returns 0
 */

int cd(int argc, char *argv[])
{
	char *directory = argc == 2 ? argv[1] : getenv("HOME");

	if (argc > 2)
	{
		fprintf(stderr, "Usage: %s [DIRECTORY]\n", argv[0]);
		return (1);
	}
	if (directory == NULL)
	{
		fprintf(stderr, "No home directory set\n");
		return (1);
	}
	if (strcmp(directory, "-") == 0)
	{
		char *prev_directory = getcwd(NULL, 0);

		if (prev_directory == NULL)
		{
			perror("getcwd");
			return (1);
		}
		if (chdir(prev_directory) != 0)
		{
			perror("chdir");
			free(prev_directory);
			return (1);
		}

		free(prev_directory);
	} else
	{
		if (chdir(directory) != 0)
		{
			perror("chdir");
			return (1);
		}
	}

	return (0);
}
