#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGUMENTS 64

int main() {
    char *command;
    char *arguments[MAX_NUM_ARGUMENTS];
    int status;

    while (1) {
        // Prompt for user input
        printf("my_shell> ");
        fflush(stdout);

        // Get user input
        command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Check for "exit" command
        if (strncmp(command, "exit", 4) == 0) {
            // Attempt to extract the status code
            int status_code;
            if (sscanf(command, "exit %d", &status_code) == 1) {
                free(command);
                exit(status_code);
            } else {
                free(command);
                exit(0);
            }
        }

        // Parse command and arguments
        char *token = strtok(command, " \n");
        int i = 0;
        while (token != NULL && i < MAX_NUM_ARGUMENTS) {
            arguments[i++] = token;
            token = strtok(NULL, " \n");
        }
        arguments[i] = NULL;

        // Fork process
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(arguments[0], arguments);
            printf("Command not found: %s\n", arguments[0]);
            exit(0);
        } else if (pid < 0) {
            // Fork failed
            printf("Fork failed\n");
        } else {
            // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }

        free(command);
    }

    return 0;
}
