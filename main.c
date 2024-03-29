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
    char *opcode; 
    char line[1024];
    unsigned int num_line = 0;
    int i;
    stack_t *stack = NULL, mod_stack;


    file = fopen(argv[1], "r");

    mod_stack = readFile(file, &stack);
    
    fclose(file);
    return (0);
}