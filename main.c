#include "shell.h"

/**
 * main - Entry point
 * Return: always return 0
 */

int main(int argc, char *argv[])
{
	char **env_var;
	char command[MAX_LINE_LENGTH];

	while (1)
	{
		printf("megnix> ");
		fflush(stdout);
		read_command(command);

		if (strcmp(command, "exit") == 0)
		{
			printf("exiting\n");
			exit(0);
		}
		else if (strncmp(command, "exit", 4) == 0)
		{
			execute_exit_command(command);
			return (1);
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


