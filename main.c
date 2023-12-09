#include <stdio.h>
#include <stdlib.h>
#include "my_getline.h"

/**
  int main() {
  FILE *file = fopen("betty.c", "r");
  if (file == NULL) {
  perror("fopen");
  return 1;
  }

  char *line = NULL;
  size_t n = 0;
  ssize_t line_length;

  while ((line_length = my_getline(&line, &n, file)) != -1) {
  printf("%s", line);
  }

  free(line);
  fclose(file);

  return 0;
  }
  */

int own_getline()
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t linecapacity;

	while ((linecapacity = my_getline(&lineptr, &n, stdin)) != -1)
	{
		printf("linecapacity: %lu, line: %s", (unsigned long) linecapacity, lineptr);

	}

	free(lineptr);
	return 0;
}

