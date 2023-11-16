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

	printf("inside pushf\n");
	if (!(data.arg))
		err1("usage: push integer", nbr, stack);

	while (data.arg[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (data.arg[i])
	{
		if (data.arg[i] < 48 || data.arg[i] > 57)
			err1("usage: push integer", nbr, stack);
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
	printf("inside pallf\n");
	if (!current)
		return;

	while (current)
	{
		printf("%i\n", current->i);
		current = current->next;
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
