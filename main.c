#include "monty.h"
/**
 * main - entry point
 * @argv: argument vector
 * @argc: argument count
 * Return: Success
*/
int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    (void)argc;

    file = fopen(argv[1], "r");

    readFile(file, &stack);
    
    fclose(file);
    return (0);
}
extern instruction_t opcodes[];