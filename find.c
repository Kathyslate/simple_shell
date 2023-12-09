/*
 * File - path.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - A command line interpreter that
 * accepts command from the standard input,handles arguments,
 * handles PATH and doesnt fork incorrect command
 */

#include "shell.h"

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
