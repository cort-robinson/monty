#include "monty.h"

/**
 * get_func - selects function from string
 * @str: Input command
 * @stack: It's the stack.
 * @line_number: Line number of file.
 * Return: function pointer
 */

int get_func(char *str, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"mod", mod},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_mode},
		{"queue", queue},
		{NULL, NULL}
	};

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(commands[i].opcode, str) == 0)
		{
			commands[i].f(stack, line_number);
			return (0);
		}
	}
	error(4, &line_number, str);
	return (1);
}
