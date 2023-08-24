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
	char *value;
	int num;
	stack_t *new_node;

	value = strtok(NULL, " \t\n");
	if (value == NULL || !is_integer(value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(value);

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
* pallStack - prints all the values on the stack,
* starting from the top of the stack
* @stack: head pointer
* @line_number: line number
*
* Return: void
*/

void pallStack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
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

instruction_t opcodes[] = {
	{"push", pushNode},
	{"pall", pallStack},
	{"pint", pintStack},
	{"pop", popStack},
	{"swap", swapStack},
	{"add", addStack},
	{"nop", nopStack},
	{"sub", subStack},
	{NULL, NULL}
};
