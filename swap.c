#include "monty.h"
/**
  * swap - swaps the top two elements of the stack
  * @stack: Double pointer to the head of the stack
  * @l: number of the line currently nbeing run
  */
void swap(stack_t **stack, unsigned int l)
{
	stack_t *nitem;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}
	nitem = (*stack)->next;
	(*stack)->next =  nitem->next;
	nitem->next = (*stack);
	(*stack)->prev = nitem;
	nitem->prev = NULL;
	*stack = nitem;
}
