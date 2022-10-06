#include "monty.h"
/**
  * add - adds the top two elements of the stack
  * @stack: Double pointer to the head of the stack
  * @l: line number being currently run
  */
void add(stack_t **stack, unsigned int l)
{
	int sum;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, l);
	(*stack)->n = sum;
}
