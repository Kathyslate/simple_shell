#include "shell.h"

/**
 * exit_shell - exits the shell
 * @status_code: status of shell
 *
 */

void exit_shell(int status_code)
{
	exit(status_code);
}

/**
 * execute_exit_command - executes command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
 */

void execute_exit_command(char *command)
{
	int status_code;

	if (sscanf(command, "exit %d", &status_code) == 1)
	{
		exit_shell(status_code);
	}
	else
	{
		exit_shell(0);
	}
}

/**
 * is_executable - reads command from standard input
 * @filename: command arguments
 *
 * Return: always returns 0
 *
 */

int is_executable(char *filename)
{
        if (access(filename, X_OK) == 0)
        {
                return (1);
        }
        return (0);
}

/**
 * read_command - reads command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
 */

void read_command(char *command)
{
        char c;
        int i = 0;

        while ((c = getchar()) != '\n' && c != EOF)
        {
                command[i++] = c;
        }
        command[i] = '\0';
}
