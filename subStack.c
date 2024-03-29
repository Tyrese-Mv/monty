#include "monty.h"
/**
 * subStack - subtracts top to nodes and make the result a head
 * @stack: the stack to manipulate
 * @line_number: line number of the opcode
 */
void subStack(stack_t **stack, unsigned int line_number)
{
	int num2, num1, res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->n;
	num2 = (*stack)->next->n;
	res = num2 - num1;

	(*stack)->next->n = res;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
