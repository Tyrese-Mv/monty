#include "monty.h"
/**
 * main - Entry point
 * @argv: arguments
 * @argc: argument count
 * Return: Success
 */
int main(int argc, char *argv[])
{
	int fileReturn;

	if (argc == 2)
	{
		fileReturn = processfile(argv[1]);
	}
	else
	{
		printf("USAGE: monty file");
		return (EXIT_FAILURE);
	}
	return (0)
}
