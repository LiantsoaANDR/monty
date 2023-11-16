#include "monty.h"
/**
 * pushf - pushes an element to the stack
 * @stack: pointer to the stack
 * @nbr: line number
 */
void pushf(stack_t **stack, unsigned int nbr)
{
	unsigned int i = 0;
	int sign = 1;

	if (!(data.arg))
	{
		fprintf(stderr, "L%i: usage: push integer", nbr);
		err1(stack);
	}

	while (data.arg[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (data.arg[i])
	{
		if (data.arg[i] < 48 || data.arg[i] > 57)
		{
			fprintf(stderr, "L%i: usage: push integer", nbr);
			err1(stack);
		}
		i++;
	}

	add_node(stack, atoi(data.arg));
}
/**
 * pallf - prints all the elements of a list
 * @stack: pointer to the stack
 * @nbr: line number, we won't use
 */
void pallf(stack_t **stack, unsigned int nbr)
{
	stack_t *current = *stack;

	(void)nbr;
	if (!current)
		return;

	while (current->next)
		current = current->next;
	while (current)
	{
		printf("%i\n", current->i);
		current = current->prev;
	}
}
/**
 * nopf - does nothing
 * @stack: pointer to the stack
 * @nbr: line number
 */
void nopf(stack_t **stack, unsigned int nbr)
{
	(void)stack;
	(void)nbr;
}
/**
 * pintf - prints the value at the top of the stack, followed by a new line
 * @stack: the stack
 * @nbr: line number
 */
void pintf(stack_t **stack, unsigned int nbr)
{
	stack_t *current = *stack;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%i: can't pint, stack empty", nbr);
		err1(stack);
	}

	while (current->next)
		current = current->next;
	printf("%i\n", current->i);
}
