#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"


int exiting(void)
{
        char command[MAX_LINE_LENGTH];

                if (strcmp(command, "exit") == 0)
                {
                        exit_handler(0);
                }

        return (0);
}
