#include <stdio.h>

#include "shell.h"

int main(int argc, char *argv[])
{
	char command[MAX_LINE_LENGTH];
	char **env_var;
	extern char **environ;


	while (1)
	{
		printf("megnix> ");
		fflush(stdout);
		read_command(command);

		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		if (execute_command(command) != 0)
		{
			break;
		}
		if (strncmp(command, "add", 3) == 0)
		{
			int num1, num2, sum;

			if (sscanf(command, "add %d %d", &num1, &num2) == 2)
			{
				sum = add(num1, num2);
				printf("Result: %d\n", sum);
			} else
			{
				printf("Error: Invalid add command\n");
			}
		}


		for (env_var = environ; *env_var != NULL; env_var++)
		{
			printf("%s\n", *env_var);
		}

		if (argc < 2)
		{
			printf("Usage: %s <command>\n", argv[0]);
			exit(1);
		}

		find_command(argv[1]);
		return (0);
	}
	return (0);
}
