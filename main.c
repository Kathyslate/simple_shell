#include "shell.h"

/**
 * main - Entry point
 * Return: always return 0
 */

int main(void)
{
	char command[MAX_LINE_LENGTH];

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("megnix> ");
			fflush(stdout);
			read_command(command);

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
	} else
	{
		while (1)
		{
			read_command(command);

			if (strncmp(command, "exit", 4) == 0)
			{
				execute_exit_command(command);
				return (1);
			}
			if (execute_command(command) == 0)
			{
				break;
			}
		}
	}
	return (0);
}

