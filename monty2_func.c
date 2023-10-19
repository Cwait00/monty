#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - responsible to add the top two values of a stack
 * @stack: pointer to the top node of the stack
 * @line_number: The current line num of a Monty bytecodes file.
 * Description: The result is stored in the second value,
 * and the top value is removed from the stack.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_number, "add"));
	return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - responsible for subtracting the top
 * value from the second value on the stack
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 * Description: The result is stored in the second value,
 * and the top value is removed from the stack
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_number, "sub"));
	return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - responsible for dividing the second,
 * value from the top by the top value on the stack.
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 * Description: The result is stored in the second value,
 * and the top value is removed from the stack.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_number, "div"));
	return;
	}
	if ((*stack)->next->n == 0)
	{
	set_op_tok_error(div_error(line_number));
	return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - is responsible for multipying the top two values,
 * on the stack.
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 * Description: The result is stored in the second value,
 * and the top value is removed from the stack.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_number, "mul"));
	return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - responsible for computing the modulus of the
 * second value from the top by the top value of the stack.
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 * Description: The result is stored in the second value,
 * and the top value is removed from the stack.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_number, "mod"));
	return;
	}

	if ((*stack)->next->n == 0)
	{
	set_op_tok_error(div_error(line_number));
	return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
