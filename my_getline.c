#include <stdio.h>
#include <stdlib.h>
#include "my_getline.h"

/**
 * my_getline - our own getline function
 * Return - always returns 0
 *
 * File - my_getline.c
 * Authors - Green Ebisine and Mercy Oyetunde
 *
 * Description - A command line interpreter that
 * accepts string from the standard input
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
	char *newline;
	ssize_t linecapacity;

	size_t buffer_size = 1024;

	if (*lineptr == NULL) {
		*n = buffer_size;
		*lineptr = malloc(*n * sizeof(char));
		if (*lineptr == NULL) {
			return -1;
		}
	}

	linecapacity = getline(lineptr, n, stream);
	if (linecapacity == -1) {
		return -1;
	}

	newline = realloc(*lineptr, linecapacity + 1);
	if (newline == NULL) {
		return -1;
	}

	*lineptr = newline;
	(*lineptr)[linecapacity] = '\0';

	return linecapacity;
}
