#include "monty.h"

/**
* rotlStack - rotates the stack
* @stack: head pointer
* @line_number: line number
*
* Return: void
*/

void rotlStack(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *sec, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	sec = (*stack)->next;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = sec;
	sec->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}
