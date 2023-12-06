#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
	static char buffer[1024];
	static size_t buffer_used = 0;
	static size_t buffer_left = 0;
	ssize_t read, total_read = 0;
	char *current;

	if (lineptr == NULL || stream == NULL || n == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (*lineptr == NULL) {
		*n = 120;
		*lineptr = malloc(*n * sizeof(char));
		if (*lineptr == NULL) {
			errno = ENOMEM;
			return -1;
		}
	}

	current = *lineptr;

	while (1) {
		if (buffer_left == 0) {
			buffer_used = 0;
			read = read(fileno(stream), buffer, sizeof(buffer));
			if (read == -1) {
				if (total_read == 0) {
					return -1;
				} else {
					break;
				}
			} else if (read == 0) {
				break;
			}
			buffer_left = read;
		}

		if (buffer[buffer_used] == '\n') {
			buffer_left--;
			buffer_used++;
			break;
		}

		if (current - *lineptr + buffer_left > *n - 1) {
			size_t new_size = *n + buffer_left + 120;
			char *new_line = realloc(*lineptr, new_size * sizeof(char));
			if (new_line == NULL) {
				errno = ENOMEM;
				return -1;
			}
			*n = new_size;
			*lineptr = new_line;
			current = *lineptr + total_read;
		}

		total_read += buffer_left;
		memcpy(current, buffer + buffer_used, buffer_left);
		current += buffer_left;
		buffer_used += buffer_left;
		buffer_left = 0;
	}

	if (total_read == 0) {
		return -1;
	}

	current[0] = '\0';
	return total_read;
}
