#include <stdio.h>

#include "shell.h"

int main(int argc, char *argv[])
{
	env(argc, argv);
	arguments(argc, argv);
	exec_shell(argc, argv);
	path(argc, argv);
	exiting();
	betty_checks();
	own_getline();

	return (0);
}
