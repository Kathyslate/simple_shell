#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit_shell(const char *args[]) {
    if (args[1] != NULL) {
        fprintf(stderr, "exit: too many arguments\n");
        return;
    }

    exit(EXIT_SUCCESS);
}

int main() {
    char *line = NULL;
    size_t size = 0;

    while (1) {
        printf("mysh> ");
        if (get_line(&line, &size, stdin) < 0) {
            exit(EXIT_SUCCESS);
        }

        argc = 0;
        args = (char **) malloc(sizeof(char *));
        token = strtok(line, " \t\r\n");

        while (token != NULL) {
            args = (char **) realloc(args, sizeof(char *) * (argc + 2));
            args[argc++] = token;
            token = strtok(NULL, " \t\r\n");
        }

        args[argc] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            exit_shell(args);
        }

 
        free(args);
    }

    return 0;
}
