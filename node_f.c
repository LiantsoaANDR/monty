#include "monty.h"
/**
 * add_node - adds a new node at the end of a stack_t
 * @head: pointer to pointer of the head
 * @n: the new element of the new node
 */
void add_node(stack_t **head, int n)
{
	stack_t *new = NULL, *current;

	new = malloc(sizeof(stack_t));

	new->i = n;
	new->next = NULL;

	if (!head || !(*head))
	{
		new->prev = NULL;
		*head = new;
		return;
	}

	current = *head;
	while (current->next)
		current = current->next;

	current->next = new;
	new->prev = current;
}
