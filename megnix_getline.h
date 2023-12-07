#ifndef _GETLINE_
#define _GETLINE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#define BUFFER_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
size_t _getline_buf_size(FILE *stream);
void _read_buffer(char *buf, size_t size, FILE *stream);
char *_resize_buffer(char *buf, size_t old_size, size_t new_size);

/*void _getline(char* input, int length);*/

#endif
