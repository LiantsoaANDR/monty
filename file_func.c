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
 * @fd: file descriptor of the file
 * @opcode: the opcode to execute
 * @arg: the argument of the opcode
 * @counter: the nth line
 */
void execute(ssize_t fd, char *opcode, char *arg, unsigned int counter)
{
	instruction_t op_f[] = {{"push", pushf}, {"pall", pallf}};
}
/**
 * pushf - push function
 * @node: pointer to the stack
 * @counter: line number
 */
void pushf(stack_t **node, unsigned int line_number)
{
}
