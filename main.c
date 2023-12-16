#include "shell.h"


int main(int argc, char *argv[])
{
    FILE *input_file;
    char *filename = argv[1];
	char input[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
	    fprintf(stderr, "./hsh: %d: Can't open %s\n", errno, filename);
        exit(0);
    }

    while (fgets(input, sizeof(input), input_file) != NULL) {
        execute_command(command);
    }

    fclose(input_file);

    return 0;
}
