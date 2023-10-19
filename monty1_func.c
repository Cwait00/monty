#include "monty.h"

/* GLOBAL OPCODE TOKENS */
char **op_toks = NULL;

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - responsiblefor pushing a value onto the stack
 * @stack: The pointer to the top node of a stack
 * @line_number: The current line num in the Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int z;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
	set_op_tok_error(malloc_error());
	return;
	}

	if (op_toks[1] == NULL)
	{
	set_op_tok_error(no_int_error(line_number));
	return;
	}

	for (z = 0; op_toks[1][z]; z++)
	{
	if (op_toks[1][z] == '-' && z == 0)
	continue;
	if (op_toks[1][z] < '0' || op_toks[1][z] > '9')
	{
	set_op_tok_error(no_int_error(line_number));
	return;
	}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
	tmp = (*stack)->next;
	new->prev = *stack;
	new->next = tmp;
	if (tmp)
	tmp->prev = new;
	(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
	tmp = *stack;
	while (tmp->next)
	tmp = tmp->next;
	new->prev = tmp;
	new->next = NULL;
	tmp->next = new;
	}
}

/**
 * monty_pall - prints all values of a stack
 * @stack: pointer to the top node of a stack
 * @line_number: The current line num in the Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
	printf("%d\n", tmp->n);
	tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - responsible to print the top value of a stack
 * @stack: pointer to the top node of a stack
 * @line_number: The current line num in the Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
	set_op_tok_error(pint_error(line_number));
	return;
	}
	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - Removes the top element of a stack
 * @stack: pointer to the top node of a stack
 * @line_number: The current line num in the Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
	set_op_tok_error(pop_error(line_number));
	return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
	next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Swaps the top two elements of a stack
 * @stack: pointer to the top node of a stack
 * @line_number: The current line num in the Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_number, "swap"));
	return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
	tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
