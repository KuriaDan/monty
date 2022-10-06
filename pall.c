#include "monty.h"
/**
  * pall - prints all items on the stack
  * @stack: double pointer to the head of the stack
  * @lineNum: linenumber being processed
  */
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *item;

	(void)(lineNum);

	if (!stack)
		return;
	for (item = *stack; ite,; item = item->next)
		printf("%d\n", item->n);
}
