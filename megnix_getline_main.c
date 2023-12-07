/*
 * File: megnix_getline_main.c
 * Authors: Green Ebisine and Mercy Oyetunde
 */
#include "megnix_getline.h"
/**
 * main - Entry point
 *
 * Return: Succesful exit
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("Enter string: ");
	while ((read = _getline(&line, &len, stdin)) != -1)
	{
		if (line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		printf("\nGotten string = %s\n", line);
		printf("Line length: %zu \n\n", strlen(line));
		printf("Enter string: ");
	}
	if (read == -1)
	{
		printf("\nEOF encountered, exiting...\n");
	}
	if (ferror(stdin))
	{
		perror("getline");
		free(line);
		exit(EXIT_FAILURE);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
