#include "monty.h"
/**
 * readf - reads a file and parses it
 * @filename: the file name from argv[1]
 */
void readf(const char *filename)
{
	char *line = NULL, *opcode, *arg;
	size_t size = 0;
	ssize_t fd;
	unsigned int counter = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fd) != -1)
	{
		opcode = strtok(line, delim);
		arg = strtok(NULL, delim);
		counter++;

		execute(opcode, arg, counter);
	}

	free(line);
	close(fd);
}
/**
 * execute - execute the opcode
 * @opcode: the opcode to execute
 * @arg: the argument of the opcode
 * @counter: the nth line
 */
void execute(char *opcode, char *arg, unsigned int counter)
{
}
