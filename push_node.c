#include "monty.h"

/**
* pushNode - push node to the stack
* @stack: head pointer
* @line_number: line number
*
* Return: void
*/

void pushNode(stack_t **stack, unsigned int line_number)
{
    char *opcode;
    int val;
    stack_t *new_node;

    opcode = strtok(NULL, " \t\n");
    if (opcode == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
    }

    val = atoi(opcode);

    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
    }
    new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
instruction_t opcodes[] = {
	{"push", pushNode},
	{"pall", pallStack},
	{"pint", pintStack},
	{"pop", popStack},
	{"swap", swapStack},
	{"add", addStack},
	{NULL, NULL}
};