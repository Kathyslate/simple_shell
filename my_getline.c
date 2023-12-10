#include <stdio.h>
#include <stdlib.h>
#include "my_getline.h"
#include <errno.h>
#include <string.h>

/**
 * my_getline - Read a line from the user into a buffer.
 *
 * @buffer: The buffer to store the read line in.
 * @max_length: The maximum number of characters to read.
 * @Return {String} the line read, or an empty string if an error occurred
 */
int my_getline(char buffer[], int max_length)
{
	int count = 0;
	int c;

	printf("Please enter a line: ");

	while ((c = getchar()) != '\n' && c != EOF && count < max_length - 1)
	{
		buffer[count++] = c;
	}

	buffer[count] = '\0';

	return ((c == EOF && count == 0) ? -1 : count);
}

/**
 * main - Entry point
 * Return: always return 0
 */

int main(void)
{
	char line[1000];
	int read_length = 0;

	while ((read_length = my_getline(line, sizeof(line))) != -1)
	{
		printf("Retrieved line of length %d :\n", read_length);
		printf("%s", line);
		printf("\n");
	}

	printf("Exited from program.\n");

	return (0);
}
