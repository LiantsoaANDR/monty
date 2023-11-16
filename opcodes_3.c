#include "monty.h"
/**
 * modfunc - computes the rest of the division of the second top
 * by the top element of the stack
 * @stack: pointer to the stack
 * @nbr: line number
 */
void modfunc(stack_t **stack, unsigned int nbr)
{
	stack_t *current = *stack;
	unsigned int count = 0;
	int res = 0;

	if (current)
	{
		count++;
		while (current->next)
		{
			count++;
			current = current->next;
		}
	}
	if (count < 2)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", nbr);
		err1(stack);
	}

	if (current->i == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", nbr);
		err1(stack);
	}
	res = current->prev->i % current->i;
	current->prev->i = res;
	current->prev->next = NULL;
	free(current);
}
