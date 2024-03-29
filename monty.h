#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pushNode(stack_t **stack, unsigned int line_number);
void pallStack(stack_t **stack, unsigned int line_number);
void pintStack(stack_t **stack, unsigned int line_number);
void popStack(stack_t **stack, unsigned int line_number);
void swapStack(stack_t **stack, unsigned int line_number);
void addStack(stack_t **stack, unsigned int line_number);






void readFile(FILE *file, stack_t **stack);
extern instruction_t opcodes[];

#endif