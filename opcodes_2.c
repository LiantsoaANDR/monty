#include "monty.h"
/**
 * swapf - swaps the the top two elements of the stack
 * @stack: pointer to the stack
 * @nbr: line number
 */
void swapf(stack_t **stack, unsigned int nbr)
{
	stack_t *current = *stack;
	unsigned int count = 0;
	int i;

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
		fprintf(stderr, "L%i: can't swap, stack too short\n", nbr);
		err1(stack);
	}

	i = current->i;
	current->i = current->prev->i;
	current->prev->i = i;
}
