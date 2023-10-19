#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - rotates the top value
 * (the value at the front of the linked list) to the bottom of the stack
 * @stack: pointer to the top node of a stack
 * @line_number: The current line num of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - rotates the bottom value
 * (the value at the end of the linked list) to the top of the stack
 * @stack: pointer to the top node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_stack - It changes the mode of the stack to 'STACK' mode
 * @stack: pointer to the top node of a stack
 * @line_number: The current line num of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - It changes the mode of the stack to 'QUEUE' mode.
 * @stack: pointer to the top mode node of a stack.
 * @line_number: The current line num of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
