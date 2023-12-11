#include "shell.h"

/**
 * read_command - reads command from standard input
 * @command: command arguments
 *
 * Return: always returns 0
 *
 * File - arguments.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - A command line interpreter that
 * accepts command from the standard input
 * and handles command lines with arguments
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
