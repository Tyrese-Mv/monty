#include "main.h"
/**
 * handleOpcode - handles processed string and passed to corresponding function
 * @processedline: line to handle
 */
void handleOpcode (char **processedline, int linenumber)
{
	int i;
	stack_t node;

	instruction_t instruct[] = {
		{ "push", pushStack},
		{ "pall", pallStack},
		{ "pop", popStack},
		{ "swap", swapStack},
		{ "add", addStack},
		{ "nop", nopStack},
		{ NULL, NULL}
	};
	while (instruct[i].opcode =! NULL)
	{
		if (strcmp(processedline[0], instruct[i].opcode) == 0)
		{

