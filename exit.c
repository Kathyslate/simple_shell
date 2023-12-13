#include "shell.h"

int exit1(void)
{
	 char command[MAX_LINE_LENGTH];

		if(strcmp(command, "exit") == 0)
		{
			exit(0);
		}
	return (0);
}
