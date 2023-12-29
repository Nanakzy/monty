#include <string.h>
#include "monty.h"

/**
 * parse_instruction - parse and execute the command
 * @line: the line to parse
 * @stack: the stack in question
 * @line_number: number of line
 * Return: 0
 */
void parse_instruction(char *line, stack_t **stack, unsigned int line_number)
{
	char *token = strtok(line, " \n\t");

	if (token)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t$");
			if (token)
			{
				int value = atoi(token);

				push(stack, value);
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(1);
			}
		}
		else if (strcmp(token, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else if (strcmp(token, "pop") == 0)
		{
			pop(stack, line_number);
		}
		else if (strcmp(token, "pint") == 0)
		{
			pint(stack, line_number);
		}
		else
		{
			fprintf(stderr, "%s:%u: invalid opcode\n", __FILE__, line_number);
			exit(1);
		}
	}
}
