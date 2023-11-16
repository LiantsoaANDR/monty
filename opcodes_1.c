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
		err1("L%i: usage: push integer\n", nbr);

	while (data.arg[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (data.arg[i])
	{
		if (data.arg[i] < 48 || data.arg[i] > 57)
			err1("L%i: usage: push integer\n", nbr);
		i++;
	}

	add_node(stack, atoi(data.arg));
}
