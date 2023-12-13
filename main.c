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
	return (0);
}


