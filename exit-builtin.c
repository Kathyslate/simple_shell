#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getline(FILE *fp) {
	char *line = NULL;
	size_t size = 0;

	if (getline(&line, &size, fp) == -1) {
		free(line);
		return NULL;
	}

	return line;
}

void exit_shell(const char *args[]) {
	if (args[1] == NULL) {
		printf("exit: usage: exit status, where status is an integer used to exit the shell\n");
		exit(EXIT_FAILURE);
	}

	int status;
	if (sscanf(args[1], "%d", &status) != 1) {
		printf("exit: usage: exit status, where status is an integer used to exit the shell\n");
		exit(EXIT_FAILURE);
	}

	exit(status);
}

int main() {
	char *line;
	char **args;
	int status;

	while (1) {
		printf("mysh> ");
		line = getline(stdin);

		if (line == NULL) {
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		args = (char **) malloc(sizeof(char *));
		int i = 0;
		char *token = strtok(line, " \t\r\n");

		while (token != NULL) {
			args = (char **) realloc(args, sizeof(char *) * (i + 2));
			args[i++] = token;
			token = strtok(NULL, " \t\r\n");
		}

		args[i] = NULL;

		if (strcmp(args[0], "exit") == 0) {
			exit_shell(args);
		}

		// More command processing logic here

		free(line);
		free(args);
	}

	return 0;
}
