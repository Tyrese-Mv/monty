#include "monty.h"
/**
 * divStack - divides top two nodes and make the result a head
 * @stack: the stack to manipulate
 * @line_number: line number of the opcode
 */
void divStack(stack_t **stack, unsigned int line_number)
{
	int num2, num1, res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->n;
	num2 = (*stack)->next->n;
	res = num2 / num1;

	(*stack)->next->n = res;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
