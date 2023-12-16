#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * builtin_cd - Entry point
 * @args: argument count
 * Return: always return 0
 */


int builtin_cd(char **argv)
{
	char cwd[1024];

	if (argv[1] == NULL)
	{
		char *home_dir = getenv("HOME");

		if (home_dir == NULL)
		{
			perror("Error: Could not get HOME environment variable");
			return (1);
		}
		if (chdir(home_dir) != 0)
		{
			perror("Error: Could not change directory");
			return (1);
		}
	} else if (strcmp(argv[1], "-") == 0)
	{
		perror("Error: Unsupported operation");
		return (1);
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("Error: Could not change directory");
			return (1);
		}
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("Error: Could not get current working directory");
		return (1);
	}

	setenv("PWD", cwd, 1);
	return (0);
}
