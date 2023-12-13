#include "shell.h"

int main(void)
{
	char command[MAX_LINE_LENGTH];

	while (1)
	{
		printf("megnix> ");
		fflush(stdout);
		read_command(command);

		if(strcmp(command, "exit") == 0)
                {
			printf("exiting\n");
                        exit(0);
                }
		if (execute_command(command) != 0)
                {
                        break;
                }
	}
	return (0);
}


