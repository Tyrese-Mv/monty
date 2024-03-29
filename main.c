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
    stack_t *stack = NULL;


    file = fopen(argv[1], "r");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        num_line++;
        opcode = strtok(line, " \t\n");
        if (opcode != NULL)
        {
            i = 0;
            while (opcodes[i].opcode)
            {
                if (strcmp(opcode, opcodes[i].opcode) == 0)
                {
                    opcodes[i].f(&stack, num_line);
                    break;
                }
                i++;
            }
        }
    }
    fclose(file);
    return (0);
}