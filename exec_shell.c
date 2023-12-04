#include "shell.h"
/**
 * simple_shell - A simple shell interpreter
 * Return - always returns 0
 *
 * File - exec_shell.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - A command line interpreter that
 * accepts command from the standard input
 */
void simple_shell(void)
{
	char input[1024];
	pid_t pid;
	int status;

	while (1)
	{
		printf("megnix> ");
		fgets(input, 1024, stdin);

		if (feof(stdin))
		{
			printf("\n");
			break;
		}

		if (strlen(input) > 1)
		{
			input[strlen(input) - 1] = '\0';
		}

		if ((pid = fork()) == 0)
		{
			execlp(input, input, (char *)NULL);
			perror("Error executing command");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}
/**
 * main - Entry point
 * Return: always return 0
 */
int main(void)
{
	simple_shell();
	return (0);
}

