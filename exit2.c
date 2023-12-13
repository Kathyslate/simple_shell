#include "shell.h"

int exit2(void)
{
	 char command[MAX_LINE_LENGTH];

	if (strncmp(command, "exit", 4) == 0)
		{
			execute_exit_command(command);
			return (1);
		}
	return (0);
}
