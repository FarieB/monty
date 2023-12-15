#include "monty.h"

/**
* add - adds the top two elements of the stack
* @stack: pointer to the head of the stack
* @line_number: current line number in the Monty byte code file
*/
void add(stack_t **stack, unsigned int line_number)
{
stack_t *current;

if (!stack || !*stack || !((*stack)->next))
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

current = *stack;
current->next->n += current->n;
pop(stack, line_number);
}

