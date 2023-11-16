#include "monty.h"
/**
 * err1 - prints an error msg on the stderr then exit
 * @msg: the msg to print
 * @line_number: where the wrong input on the file
 * @stack: stack_t stack to be freed
 */
void err1(char *msg, unsigned int line_number, stack_t **stack)
{
	fprintf(stderr, "L%i: %s\n", line_number, msg);
	free_stack(*stack);
	free(data.line);
	close(data.file);
	exit(EXIT_FAILURE);
}
