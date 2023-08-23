#include "monty.h"
/**
 * pushOpcode - pushes information to the stack
 * @stack: the overall stack data structure
 * @linenumber: number of the line
 * @data: data to be added
 */
void pushOpcode(stack_t **stack, int linenumber, int data)
{
	stack_t newNode = malloc(sizeof(stack_t));

	newNode->n = data;
	newNode->prev = NULL;
	newNode->next = NULL; /**We can use the global variable as the head if we declare as head*/
	/**assume the stack is empty*/



