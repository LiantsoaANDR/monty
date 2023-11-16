#include "monty.h"
/**
 * err1 - frees the stack and the line in memory and close the file
 * @stack: stack_t stack to be freed
 */
void err1(stack_t **stack)
{
	free_stack(*stack);
	if (data.line)
		free(data.line);
	fclose(data.file);
	exit(EXIT_FAILURE);
}
