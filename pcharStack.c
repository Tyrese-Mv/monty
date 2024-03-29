#include "monty.h"

/**
* pcharStack - prints the char at the top of the stack
* @stack: head pointer
* @line_number: line number
*
* Return: void
*/

void pcharStack(stack_t **stack, unsigned int line_number)
{
	int asciiValue;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	asciiValue = (*stack)->n;
	if (asciiValue < 0 || asciiValue > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", asciiValue);
}
