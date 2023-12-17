#define _GNU_SOURCE
#include "monty.h"

/**
* main - entry point for the Monty interpreter
* @argc: argument count
* @argv: array of arguments
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
FILE *file;
char *line = NULL;
size_t len = 0;
stack_t *stack = NULL;
unsigned int line_number = 0;
instruction_t instruction;

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

while (getline(&line, &len, file) != -1)
{
line_number++;
instruction = get_instruction(line, line_number);
if (instruction.opcode)
{
void (*op_func)(stack_t **, unsigned int) = get_opcode_function(instruction.opcode);
if (op_func)
op_func(&stack, line_number);
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction.opcode);
free_stack(&stack);
free(line);
fclose(file);
exit(EXIT_FAILURE);
}
}
}

free_stack(&stack);
free(line);
fclose(file);

return (EXIT_SUCCESS);
}
