/*
 * File: megnix_getline_func.c
 * Author: Green Ebisine and Mercy Oyetunde
 *
 * Description: A function to get input from stdin
 * and output the lengh of strings
 */
#include "shell.h"
/**
 * _getline - Function to get line from stdin
 * @lineptr: Pointer to a string
 * @n: Pointer to a size variable
 * @stream: Stream of data input
 *
 * Return: Length of data from standard input
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || stream == NULL || n == NULL)
	{
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*n = 120;
		*lineptr = malloc(*n * sizeof(char));
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	return (read_line(*lineptr, *n, stream));
}

ssize_t read_line(char *bufptr, size_t size, FILE *stream)
{
	char *p = bufptr;
	int c;

	c = fgetc(stream);
	if (c == EOF)
	{
		return (-1);
	}

	p = bufptr;
	while (c != EOF)
	{
		if ((size_t)(p - bufptr) > (size - 1))
		{
			size = size * 2;
			bufptr = realloc(bufptr, size * sizeof(char));
			if (bufptr == NULL)
			{
				return (-1);
			}
		}

		*p++ = c;
		if (c == '\n')
		{
			break;
		}
		c = fgetc(stream);
	}

	*p++ = '\0';

	return (p - bufptr - 1);
}
