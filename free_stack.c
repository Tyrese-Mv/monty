#include "monty.h"

/**
* free_stack - free memory allocated for a stack
* @stack: head pointer
*
* Return: void
*/

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
