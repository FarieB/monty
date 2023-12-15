#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: pointer to the head of the stack
* @line_number: current line number in the Monty byte code file
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !*stack)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = temp->next;

if (*stack)
(*stack)->prev = NULL;

free(temp);
}

