#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction in the Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(1);
	}
	printf("%d\n", (*stack)->n);

	temp = *stack;
	*stack = temp->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
