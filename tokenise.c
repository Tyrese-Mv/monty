#include "monty.h"
/**
 * tokenise - tokenises the string for execution
 * @str:  string to be tokenised
 * Return: string
 */

char **tokenise(char *str)
{
	char **stringtok, *token;
	size_t buf = 50;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}

	stringtok = malloc(sizeof(char *) * buf);

	if (stringtok == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \n\t");
	for (i = 0; token != NULL; i++)
	{
		stringtok[i] = token;
		token = strtok(str, " \n\t");
	}
	stringtok[i] = NULL;
	return (stringtok);
}
