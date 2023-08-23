#include "monty.h"
/**
 * processfile - processes the monty file
 * @filename: file to be opened
 * Return: SUCCESS of FAILURE
 */
int processfile (char *filename)
{
	char *line;
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
		handleOpcode(processedline);

