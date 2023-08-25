#ifndef MONTY_H
#define MONTY_H

/* C - library functions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Data structure */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t opcodes[];

/* Function Prototypes */
void check_open_file(FILE *file, char **argv);
void pushNode(stack_t **stack, unsigned int line_number);
void pallStack(stack_t **stack, unsigned int line_number);
void pintStack(stack_t **stack, unsigned int line_number);
void popStack(stack_t **stack, unsigned int line_number);
void swapStack(stack_t **stack, unsigned int line_number);
void addStack(stack_t **stack, unsigned int line_number);
void nopStack(stack_t **stack, unsigned int line_number);
void subStack(stack_t **stack, unsigned int line_number);
void divStack(stack_t **stack, unsigned int line_number);
void mulStack(stack_t **stack, unsigned int line_number);
void modStack(stack_t **stack, unsigned int line_number);
void pcharStack(stack_t **stack, unsigned int line_number);
void pstrStack(stack_t **stack, unsigned int line_number);
void rotlStack(stack_t **stack, unsigned int line_number);
int is_integer(const char *str);
void free_stack(stack_t *stack);
#endif
