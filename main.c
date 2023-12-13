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
            exiting();
	    break;
        }
	if (strncmp(command, "exit", 4) == 0)
                {
                        execute_exit_command(command);
                } 
	if (execute_command(command) != 0)
                {
                        break;
                }
	}
	return (0);
}
