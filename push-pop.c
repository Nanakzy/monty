#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @value: Value to be pushed.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(1);
	}
	new_node->n = value;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}

/**
 * pop - Pops the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction in the Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(1);
	}

	temp = *stack;

	if (temp->next)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}
