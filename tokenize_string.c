#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - takes a string str and a set of delimiters delims as input.
 * @str: string to seperate into word
 * @delims: delimiters to use to delimit words
 * Return: 2D array of pointers to each word
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, a = 0;

	if (str == NULL || !*str)
	return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
	return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
	return (NULL);
	while (a < wc)
	{
	wordLen = get_word_length(str, delims);
	if (is_delim(*str, delims))
	{
	str = get_next_word(str, delims);
	}
	words[a] = malloc((wordLen + 1) * sizeof(char));
	if (words[a] == NULL)
	{
	while (a >= 0)
	{
	a--;
	free(words[a]);
	}
	free(words);
	return (NULL);
	}
	n = 0;
	while (n < wordLen)
	{
	words[a][n] = *(str + n);
	n++;
	}
	words[a][n] = '\0'; /* set end of str */
	str = get_next_word(str, delims);
	a++;
	}
	words[a] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delim - checks if a given character ch is a delimiter.
 * @ch: character in stream
 * @delims: Pointer to null terminated array of delimiter
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int b = 0;

	while (delims[b])
	{
	if (delims[b] == ch)
	return (1);
	b++;
	}
	return (0);
}

/**
 * get_word_length - calculates the length of
 * the current word in a string.
 * @str: string to get word length from current word
 * @delims:  takes the string str and a string,
 * of delimiters delims as input.
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, z = 0;

	while (*(str + z))
	{
	if (is_delim(str[z], delims))
	pending = 1;
	else if (pending)
	{
	wLen++;
	}
	if (wLen > 0 && is_delim(str[z], delims))
	break;
	z++;
	}
	return (wLen);
}

/**
 * get_word_count - calculates the total number of words in a string.
 * @str: string to get word count from
 * @delims: takes the string str and a string of delimiters delims as input.
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, g = 0;

	while (*(str + g))
	{
	if (is_delim(str[g], delims))
	pending = 1;
	else if (pending)
	{
	pending = 0;
	wc++;
	}
	g++;
	}
	return (wc);
}

/**
 * get_next_word - gets the next word in a string_t
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int d = 0;

	while (*(str + d))
	{
	if (is_delim(str[d], delims))
	pending = 1;
	else if (pending)
	break;
	d++;
	}
	return (str + d);
}
