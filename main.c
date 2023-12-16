#include "shell.h"


int main(int argc, char *argv[])
{
    FILE *input_file;
    char input[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(input, sizeof(input), input_file) != NULL) {
        execute_command(command);
    }

    fclose(input_file);

    return 0;
}
