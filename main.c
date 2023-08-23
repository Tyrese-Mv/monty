#include "monty.h"

/**
 * main - Entry point
 * @argv: arguments
 * @argc: argument count
 * Return: Success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *opcode;
	char line[1024];
	unsigned int line_number = 0;
	int i;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	check_open_file(file, argv);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode)
		{
			i = 0;
			while (opcodes[i].opcode)
			{
				if (strcmp(opcode, opcodes[i].opcode) == 0)
				{
					opcodes[i].f(&stack, line_number);
					break;
				}
				i++;
			}
			if (!opcodes[i].opcode)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
	return (0);
}

/**
* check_open_file - checks if the file passed, can be opened.
* @file: file
* @argv: arguments passed
*
* Return: nothing, prints error msg to stderr on failure
*/

void check_open_file(FILE *file, char **argv)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
