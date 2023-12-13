#include "megnix_getline.h"
/**
 * megnix_getline - Read a line from the user into a buffer.
 *
 * @buffer: The buffer to store the read line in.
 * @max_length: The maximum number of characters to read.
 *
 * Return: String the line read, or an empty string if an error occurred
 */
int megnix_getline(char buffer[], int max_length)
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

