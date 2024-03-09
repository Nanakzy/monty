#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
