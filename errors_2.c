#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - handle errors when attempting to pop from an empty stack
 * @line_number: Line num in script where error occured.
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - handles errors when trying to print the,
 * top element of an empty stack.
 * @line_number: Line num in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - This function handles errors related to math
 * operations (e.g., add, sub) when the stack or queue
 * is smaller than two nodes.
 * @line_number: Line num in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division by zero errors.
 * @line_number: Line num in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints  errors when trying to print a character from an
 * empty stack or when the character value is not within the valid range (0-12
 * @line_number: Line num in Monty bytecodes file where error occurred.
 * @message: The equivalent error message to print.
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
