#include "monty.h"

/**
 * f_pall - Prints all the values on the stack.
 * @stack: A pointer to the stack's top.
 * @line_number: The current line number (unused).
 */
void f_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
