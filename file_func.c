#include "monty.h"
/**
 * readf - reads a file and parses it
 * @filename: the file name from argv[1]
 */
void readf(const char *filename)
{
	size_t size = 0;
	ssize_t read;
	unsigned int l = 0;
	stack_t *stack = NULL;
	FILE *file;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	data.file = file;
	read = getline(&data.line, &size, file);
	while (read != -1)
	{
		l++;
		exec(l, &stack);
		read = getline(&data.line, &size, file);
	}
	if (data.line)
		free(data.line);
	fclose(file);
	free_stack(stack);
}
/**
 * exec - exec the opcode
 * @l: the nth line
 * @stack: the stack
 */
void exec(unsigned int l, stack_t **stack)
{
	instruction_t op_f[] = {{"push", pushf}, {"pall", pallf},
				{"nop", nopf}, {"pint", pintf},
				{"pop",popf}, {NULL, NULL}};
	char *code = NULL, *delim = " \t\n";
	unsigned int i = 0;

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

	fprintf(stderr, "L%i: unknown instruction %s\n", l, code);
	free_stack(*stack);
	if (data.line)
		free(data.line);
	fclose(data.file);
	exit(EXIT_FAILURE);
}
