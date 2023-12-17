#include "monty.h"

/**
* free_stack - Frees a stack.
* @stack: Pointer to the head of the stack.
*/
void free_stack(stack_t **stack)
{
stack_t *current = *stack;
stack_t *next;

while (current)
{
next = current->next;
free(current);
current = next;
}

*stack = NULL;
}
