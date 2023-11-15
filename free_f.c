#include "monty.h"
/**
 * free_stack - frees a stack_t list
 * @head: pointer to the head of the list
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;

	while (current)
	{
		current = current->next;
		free(head);
		head = current;
	}
}
