#include "monty.h"
/**
 * popStack - removes the top element of the stack
 * @stack: the stack to manipulate
 * @line_number: line number of the opcode
 */
void popStack(stack_t **stack, unsigned int line_number)
{
	stack_t *tempNode = (*stack);

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tempNode->next == NULL)
	{
		*stack = NULL;
		free(tempNode);
	}
	else
	{
		*stack = tempNode->next;
		(*stack)->prev = NULL;
		free(tempNode);
	}
}
