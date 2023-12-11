#include "megnix_getline.h"
/**
 * main - Entry point
 * Return: always return 0
 */

int main(void)
{
	char line[1000];
	int read_length = 0;

	while ((read_length = megnix_getline(line, sizeof(line))) != -1)
	{
		printf("\nLine of length: %d \n", read_length);
		printf("Gotten Line: %s \n\n", line);
	}
	if (read_length == -1)
	{
		printf("\n\nEOF encountered, exiting...\n");
	}
	return (0);
}

