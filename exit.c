#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"


int exiting(void)
{
        char command[MAX_LINE_LENGTH];


        while (1)
        {
                printf("megnix> ");
                fflush(stdout);
                read_command(command);

                if (strcmp(command, "exit") == 0)
                {
                        exit_handler(0);
                }
                if (execute_command(command) != 0)
                {
                        break;
                }
        }

        return (0);
}
