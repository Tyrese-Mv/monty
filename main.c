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
	stack_t *stack = NULL, *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	readFile(file, &stack);
	fclose(file);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = NULL;
	return (0);
}

