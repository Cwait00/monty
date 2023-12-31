#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * main - entry point for Monty Interpreter
 * @argc: the num of arguments passed to the program
 * @argv: an array of strings containing the program
 * name and its arguments
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
	return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
