#include "monty.h"

/**
* pall - prints all the values on the stack
* @stack: pointer to the head of the stack
* @line_number: current line number in the Monty byte code file
*/
void pall(stack_t **stack, unsigned int line_number)
{
(void)line_number;

stack_t *current = *stack;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

