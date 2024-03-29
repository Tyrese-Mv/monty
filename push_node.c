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
	if (opcode == NULL || !is_integer(opcode))
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

/**
* is_integer - checks if the string is a number
* @str: string
*
* Return: 1 if number else 0
*/

int is_integer(const char *str)
{
	char *endptr;

	if (str == NULL || *str == '\0' || isspace(*str))
		return (0);

	strtol(str, &endptr, 10);

	return (*endptr == '\0');
}
