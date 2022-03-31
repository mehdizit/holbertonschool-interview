#include "substring.h"
/**
 * find_substring - finds all the possible substrings
 * containing a list of words, within a given string
 * @s: the given string
 * @words: the words that will form the substring
 * @nb_words: number of words
 * @n: number of indices found
 * Return: an allocated array,
 * storing each index in s, at which a substring was found.
 * If no solution is found, return NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i = 0, full_loop, x, l, duble = 0, next_word = -1, idx = 0, *tracker;
	int *indices = NULL, raw_idx[1024];

	reset_array(raw_idx, 1024, -1);
	tracker = malloc(sizeof(int) * nb_words);
	reset_array(tracker, nb_words, 0);
	while (contains_0_1(tracker, nb_words) > -1 && s[i])
	{
		full_loop = 1;
		for (x = 0; x < nb_words; x++)
		{
			duble = 0;
			if (tracker[x] == 0)
				l = compare((char *)&s[i], (char *)words[x]);
			else
			{
				duble = 1;
				l = -1;
			}
			if (l != -1)
			{
				if (contains_0_1(tracker, nb_words) == 1)
				{
					raw_idx[idx] = i;
					next_word = i + l;
				}
				full_loop = 0;
				i += l;
				tracker[x] = 1;
				break;
			}
		}
		if (contains_0_1(tracker, nb_words) == -1)
		{
			idx++;
			reset_array(tracker, nb_words, 0);
		}
		if (full_loop || (!s[i] && contains_0_1(tracker, nb_words) > -1))
		{
			raw_idx[idx] = -1;
			reset_array(tracker, nb_words, 0);
			if (s[i] && duble && next_word != -1)
				i = next_word;
			else
				i++;
		}
	}
	indices = fill_indices(raw_idx, indices, n);
	free(tracker);
	return (indices);
}
/**
 * reset_array - fills an array with a specific value
 * @array: the array
 * @len: the length of the array
 * @value: the value to fill the array with
 * Return: void
 */
void reset_array(int *array, int len, int value)
{
	int i;

	for (i = 0; i < len; i++)
		array[i] = value;
}
/**
 * contains_0_1 - checks if all elements in array tracker, are zeroes
 * @tracker: the array
 * @nb_words: the length of the array
 * Return: 1 if there are only zeroes, 0 if there are both zeroes and ones
 * and -1 if there are only 1
 */
int contains_0_1(int *tracker, int nb_words)
{
	int i, check_ones = 0, check_zeroes = 0;

	for (i = 0; i < nb_words; i++)
	{
		if (tracker[i] == 1)
			check_ones = 1;
		if (tracker[i] == 0)
			check_zeroes = 1;
	}
	if (check_zeroes && !check_ones)
		return (1);
	if (check_zeroes && check_ones)
		return (0);
	return (-1);
}
/**
 * compare - checks if the substring word is in the beginning of the string s
 * @s: the string
 * @word: the substring
 * Return: 1 if it exists, 0 if not
 */
int compare(char *s, char *word)
{
	int i = 0;

	if (!s[i] && !word[i])
		return (0);
	while (word[i])
	{
		if (s[i] != word[i])
			return (-1);
		i++;
	}
	return (i);
}
/**
 * fill_indices - fill the array indices with values from the array raw_idx
 * @raw_idx: a long array that contains indexes values + -1 values
 * @indices: the array to be filled with only indexes values
 * @n: address of the integer where the number of indexes will be stored
 * Return: the array indices filled with only indexes values
 */
int *fill_indices(int *raw_idx, int *indices, int *n)
{
	int i = 0;

	while (raw_idx[i] != -1)
		i++;
	*n = i;
	indices = malloc(sizeof(int) * (*n));
	if (!indices)
	{
		*n = 0;
		return (NULL);
	}
	for (i = 0; i < (*n); i++)
	{
		indices[i] = raw_idx[i];
	}
	return (indices);
}