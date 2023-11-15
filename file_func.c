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
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fd) != -1)
	{
		l++;
		exec(fd, line, l, node);
	}

	free(line);
	close(fd);
}
/**
 * exec - exec the opcode
 * @fd: file descriptor of the file
 * @line: the content of the l nt line of the file
 * @l: the nth line
 * @stack: the stack
 */
void exec(ssize_t fd, line,unsigned int l, stack_t **stack)
{
	instruction_t op_f[] = {{"push", pushf}, {"pall", pallf}};
	char *code= NULL, *str = NULL, *delim = " \t\n"

	data.line = l;
	data.file = fd;

	code = strtok(line, delim);
	data.arg = strtok(NULL, delim);
	while (code && op_f[i].opcode)
	{
		if (strcmp(code, op_f[i].opcode) == 0)
		{
			op_f[i].f(stack, counter);
			return;
		}
		i++;
	}

	if (op)
	{
		dprintf(STDERR_FILENO, "L%i: unknown instruction %s", l, code);
		free_stack(*stack);
		free(line);
		close(fd);
		exit(EXIT_FAILURE);
	}
}
/**
 * pushf - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pushf(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	if (!(data.arg))
	{
		dprintf(STDERR_FILENO, "L%i: usage: push integer", data.line);
	}
}
