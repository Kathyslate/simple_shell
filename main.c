#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: always return 0
 */
int main(int argc, char *argv[])
{
	parse(argc, argv);
	setenv_builtin(argc, argv);
	cd(argc, argv);
	unsetenv_builtin(argc, argv);

	return (0);
}
