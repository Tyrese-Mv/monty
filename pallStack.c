#include "monty.h"

/**
* pallStack - prints all the values on the stack,
* starting from the top of the stack
* @stack: head pointer
* @line_number: line number
*
* Return: void
*/

void pallStack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}