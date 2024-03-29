#include "monty.h"

/**
* pstrStack -prints the string from top of the stack
* @stack: head pointer
* @line_number: line number
*
* Return: void
*/

void pstrStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;

	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
