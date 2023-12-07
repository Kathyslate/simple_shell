/*
 * File: megnix_getline_func.c
 * Author: Green Ebisine and Mercy Oyetunde
 *
 * Description: A function to get input from stdin
 * and output the lengh of strings
 */
#include "megnix_getline.h"
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
	if (stream == NULL || lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*n = _getline_buf_size(stream);
		*lineptr = (char *) malloc(*n * sizeof(char));
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	size_t len = 0;

	while (1)
	{
		char *buf = *lineptr + len;

		_read_buffer(buf, *n - len, stream);
		len += strlen(buf);

		if (*n < len + 1 || buf[len - 1] != '\n')
		{
			*n *= 2;
			*lineptr = _resize_buffer(*lineptr, *n / 2, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		else
		{
			break;
		}
	}
	return (len);
}
/**
 * _getline_buf_size - Function to get buffer size
 * @stream: Data input stream
 *
 * Return: BUFFFER_SIZE
 */
size_t _getline_buf_size(FILE *stream)
{
	return (BUFFER_SIZE);
}
/**
 * _read_buffer - Function to read buffer
 * @buf: Char buff variable
 * @size: Size varaible
 * @stream: Data input stream
 */
void _read_buffer(char *buf, size_t size, FILE *stream)
{
	if (fgets(buf, size, stream) == NULL)
	{
		return;
	}
}
/**
 * _resize_buffer - Function resize buffer for stdin
 * @buf: Buffer size
 * @old_size: Size variable
 * @new_size: Size variable
 *
 * Return: New buffer size
 */
char *_resize_buffer(char *buf, size_t old_size, size_t new_size)
{
	char *new_buf = (char *) realloc(buf, new_size * sizeof(char));

	return (new_buf);
}
