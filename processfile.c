#include "monty.h"
/**
 * processfile - processes the monty file
 * @filename: file to be opened
 * Return: SUCCESS of FAILURE
 */
int processfile (char *filename)
{
	char line[50];
	File *file;
	int i = 1;
	char **processedline;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s", filename);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		processedline = tokenise(line);
		if (processedline[0] == "push")
			handlepush(processedline, i);
		handleOpcode(processedline, i);
		i++;
	}
	fclose(filename);
	return (0);
}

/**
 * newStack - initialises a new stack
 * @stack: head node
 *
void newStack(firstNode *stack)
{
	stack->top = NULL;*/
