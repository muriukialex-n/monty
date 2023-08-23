#include "monty.h"

/**
 * f_push - Pushes an element onto the stack.
 * @stack: A pointer to the stack's top.
 * @line_number: The current line number.
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!is_integer(bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = atoi(bus.arg);
	addnode(stack, value);
}
