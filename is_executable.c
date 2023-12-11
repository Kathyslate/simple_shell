/*
 * File - path.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - A command line interpreter that
 * accepts command from the standard input,handles arguments,
 * handles PATH and doesnt fork incorrect command
 */

#include "shell.h"

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
