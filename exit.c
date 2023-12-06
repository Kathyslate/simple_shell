#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_ARGUMENTS 64

int is_built_in(char *command);
void execute_built_in(char *command);

int main() {
    char command[MAX_COMMAND_SIZE];
    char *arguments[MAX_ARGUMENTS];
    int should_run = 1;

    while (should_run) {
        printf("> ");
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (is_built_in(command)) {
            execute_built_in(command);
        } else {
            int pid = fork();
            if (pid == 0) {
                char *path = getenv("PATH");
                char *token = strtok(path, ":");
                while (token != NULL) {
                    char filepath[1024];
                    snprintf(filepath, sizeof(filepath), "%s/%s", token, command);
                    if (access(filepath, F_OK) != -1) {
                        arguments[0] = command;
                        arguments[1] = NULL;
                        execv(filepath, arguments);
                        break;
                    }
                    token = strtok(NULL, ":");
                }
                if (token == NULL) {
                    printf("command not found: %s\n", command);
                }
                exit(0);
            } else if (pid < 0) {
                printf("fork failed\n");
            } else {
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}

int is_built_in(char *command) {
    if (strcmp(command, "exit") == 0) {
        return 1;
    }
    return 0;
}

void execute_built_in(char *command) {
    if (strcmp(command, "exit") == 0) {
        exit(0);
    }
}
