#include <string.h>
#include "monty.h"

/**
* get_opcode_function - Returns a function pointer for a given opcode.
* @opcode: The opcode to look for.
* Return: A function pointer to the corresponding function,
* or NULL if not found.
*/
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int)
{
instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{NULL, NULL},
{"add", add},
};

int i = 0;
while (instructions[i].opcode)
{
if (strcmp(instructions[i].opcode, opcode) == 0)
return (instructions[i].f);
i++;
}

return (NULL);
}

