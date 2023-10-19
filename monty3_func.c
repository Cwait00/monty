#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - is associated with the 'nop' opcode in the Monty language.
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Prints the character representation
 * of the top value on the stack.
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
	set_op_tok_error(pchar_error(line_number, "stack empty"));
	return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
	set_op_tok_error(pchar_error(line_number,
		"value out of range"));
	return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string that consist of characters
 * from a stack until a NULL byte (0) is encounted, or until
 * a character outside a valid ASCII range (0-127) is encounted.
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
	printf("%c", tmp->n);
	tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
