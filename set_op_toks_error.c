#include "monty.h"

/**
 * set_op_tok_error - Sets last element of 'op_toks' to be an error code.
 * @error_code: Integer as an argument
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, a = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
	malloc_error();
	return;
	}
	while (a < toks_len)
	{
	new_toks[a] = op_toks[a];
	a++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
	free(new_toks);
	malloc_error();
	return;
	}
	new_toks[a++] = exit_str;
	new_toks[a] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
