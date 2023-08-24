#include "monty.h"
/**
 * swapStack - swap top two elements in the stack
 * @stack: the stack to manipulate
 * @line_number: line number of the opcode
 */
void swapStack(stack_t **stack, unsigned int line_number)
{
	int num1, num2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num1 = (*stack)->n;
	num2 = (*stack)->next->n;

	(*stack)->n = num2;
	(*stack)->next->n = num1;
}
