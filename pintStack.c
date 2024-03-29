#include "monty.h"

/**
* pintStack - prints the top node value
* @stack: head pointer
* @line_number: line number
* Return: void
*/

void pintStack(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
