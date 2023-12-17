#include <string.h>
#include "monty.h"

/**
* get_instruction - Parses a line and returns an instruction structure.
* @line: Line of Monty bytecode.
* @line_number: Line number in the Monty bytecode file.
* Return: An instruction structure.
*/
instruction_t get_instruction(char *line)
{
instruction_t instruction;
char *opcode;

opcode = strtok(line, " \t\n");
instruction.opcode = opcode;
instruction.f = NULL;

return (instruction);
}
