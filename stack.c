#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Frees all the memory associated with a stack (or queue)
 * @stack: sets a pointer to the top (stack) or
 * bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	}
}

/**
 * init_stack - initializes a stack (or queue) with a starting node.
 * @stack: A pointer to an unitialized stack_t stack as an argument
 * Return: If an error occurs - EXIT_FAILURE.
 * Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
	return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks the mode of a stack_t linked list.
 * @stack: A pointer to the top (stack) or bottom (queue),
 * of the linked list as an argument.
 * Return: If the stack is in stack mode - STACK (0).
 * If the stack is in queue mode - QUEUE (1).
 * Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
	return (STACK);
	else if (stack->n == QUEUE)
	return (QUEUE);
	return (2);
}
