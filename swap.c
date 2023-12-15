#include "monty.h"

/**
* swap - swaps the top two elements of the stack
* @stack: pointer to the head of the stack
* @line_number: current line number in the Monty byte code file
*/
void swap(stack_t **stack, unsigned int line_number)
{
int temp;
stack_t *current;

if (!stack || !*stack || !((*stack)->next))
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

current = *stack;
temp = current->n;
current->n = current->next->n;
current->next->n = temp;
}

