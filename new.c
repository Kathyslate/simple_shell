#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

int execute_command(char *command)
{
    char *arguments[10];
    int num_args = 0;
    pid_t pid;
    int status;

    command = strtok(command, " \n");
    arguments[num_args++] = command;

    while ((arguments[num_args++] = strtok(NULL, " \n")) != NULL)
        ;

    pid = fork();
    if (pid == 0) {
        execvp(command, arguments);
        perror("execvp");
        exit(2);
    } else if (pid < 0) {
        perror("fork");
        exit(2);
    } else {
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
        }
    }
    return (status);
}



int inputedd(int argc, char *argv[])
{
    FILE *input_file;
    char input[1024];
    (void)argc;

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(input, sizeof(input), input_file) != NULL) {
        execute_command(command);
    }

    fclose(input_file);

    return 0;
}
