#ifndef _GETLINE_
#define _GETLINE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <errno.h>
#define BUFFER_SIZE 1024

int megnix_getline(char buffer[], int max_length);

#endif

