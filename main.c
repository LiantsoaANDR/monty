#include "monty.h"
data_t data = {NULL, 0, 0}
/**
 * main - interpreter for Monty ByteCodes files
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	readf(argv[1]);

	return (0);
}
