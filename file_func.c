#include "monty.h"
/**
 * readf - reads a file and parses it
 * @filename: the file name from argv[1]
 */
void readf(const char *filename)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t fd;
	unsigned int l = 0;
	stack_t **stack = NULL;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fd) != -1)
	{
		l++;
		data.line = line;
		exec(fd, l, stack);
	}

	free(line);
	close(fd);
}
/**
 * exec - exec the opcode
 * @fd: file descriptor of the file
 * @l: the nth line
 * @stack: the stack
 */
void exec(ssize_t fd, unsigned int l, stack_t **stack)
{
	instruction_t op_f[] = {{"push", pushf}, {NULL, NULL}};
	char *code = NULL, *delim = " \t\n";
	unsigned int i = 0;

	data.file = fd;

	code = strtok(data.line, delim);
	data.arg = strtok(NULL, delim);
	while (code && op_f[i].opcode)
	{
		if (strcmp(code, op_f[i].opcode) == 0)
		{
			op_f[i].f(stack, l);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%i: unknown instruction %s", l, code);
	free_stack(*stack);
	free(data.line);
	close(fd);
	exit(EXIT_FAILURE);
}
