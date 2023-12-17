#include <stdio.h>
#include <sys/types.h>
#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>


/**
* main - Entry point for the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
FILE *file;
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0;
ssize_t read;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <file>\n", argv[0]);
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while ((read = getline(&line, &len, file)) != -1)
{
unsigned int line_number = 1;
instruction_t instruction = get_instruction(line, line_number);
if (instruction.f)
{
instruction.f(&stack, line_number);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction.opcode);
free_stack(&stack);
free(line);
fclose(file);
exit(EXIT_FAILURE);
}

line_number++;
}

free_stack(&stack);
free(line);
fclose(file);

return EXIT_SUCCESS;
}

