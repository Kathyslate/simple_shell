#include "shell.h"

/**
 * main - Entry point
 * @argv: vector
 * @argc: count
 * Return: always return 0
 */

int main(int argc, char *argv[])
{
	char command[MAX_LINE_LENGTH];
	(void)argc;

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
		if (strncmp(command, "exit", 4) == 0)
		{
			execute_exit_command(command);
			return (1);
		}
		if (execute_command(command) != 0)
		{
			break;
		}
	}
	find_command(argv[1]);
	return (0);
}


