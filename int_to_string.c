#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
	char *buff, int buff_size);

/**
 * get_int - takes an integer num as its argument and returns
 * a character pointer (string).
 * @num: num to convert to string.
 * Return: character pointer to newly string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
	length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
	return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
	ret[0] = '-';

	return (ret);
}

/**
 * _abs - takes an integer i as its argument and returns
 * its absolute value as an unsigned integer.
 * @i: integer to get absolute value of
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
	return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - calculates the length needed to represent
 * an unsigned integer num in a specified base.
 * @num: num to get length needed for
 * @base: base of num representation used by buffer
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
	len++;
	num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills a character buffer (buff) with the
 * digits representing an unsigned integer num in a specified base,up to 36
 * @num: num to convert to string given base
 * @base: base of num used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
	char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
	rem = num % base;
	if (rem > 9) /* return lowercase ascii val representation */
	buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
	else
	buff[i] = rem + '0';
	num /= base;
	i--;
	}
}
