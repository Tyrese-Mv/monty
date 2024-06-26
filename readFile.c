#include "monty.h"
/**
 * readFile - Read commands in a file
 * @file: file stream
 * @stack: stack to be manipulated
 * Return: Stack
*/

void readFile(FILE *file, stack_t **stack)
{
	char *opcode, *spaces;
	char line[1024];
	unsigned int num_line = 0;
	int i;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		num_line++;
		spaces = line;
		while (isspace((unsigned char)*spaces))
			spaces++;
		if (*spaces == '#' || *spaces == '\n')
			continue;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL)
		{
			i = 0;
			while (opcodes[i].opcode)
			{
				if (strcmp(opcode, opcodes[i].opcode) == 0)
				{
					opcodes[i].f(stack, num_line);
					break;
				}
				i++;
				if (!opcodes[i].opcode)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", num_line, opcode);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
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
	{"div", divStack},
	{"mul", mulStack},
	{"mod", modStack},
	{"pchar", pcharStack},
	{"pstr", pstrStack},
	{"rotl", rotlStack},
	{NULL, NULL}
};

