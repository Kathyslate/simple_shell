#include "shell.h"

#define MAXLINE 1024

int execute_command(char *command)
{
	char *argv[MAXLINE / 2 + 1];
	int status;
	int i = 1;
	pid_t pid;

	if (strncmp(command, "exit", 4) == 0) {
		int status_code;

		if (sscanf(command, "exit %d", &status_code) == 1) {
			exit(status_code);
		} else {
			exit(0);
		}
	}

	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}

	if (pid == 0) {
		argv[0] = strtok(command, " \t\n");
		while ((argv[i++] = strtok(NULL, " \t\n"))) {
			continue;
		}

		if (execvp(argv[0], argv) < 0) {
			perror("exec");
			exit(1);
		}
	}

	if (waitpid(pid, &status, 0) < 0) {
		perror("waitpid");
		exit(1);
	}

	return (status);
}

