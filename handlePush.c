#include "monty.h"
/**
 * handlepush - handles the push opcode
 * @processedline: tokenised line to be processed
 * @linenumber: the line number
 */
void handlepush (char **processedline, int linenumber)
{
	/**assume that processedline[1] is a number*/
	/**need to have a global variable for stack*/
	pushOpcode(&stack, linenumber, processedline[1]);
}
