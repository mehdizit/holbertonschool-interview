
#include "substring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * find_substring -  finds all the possible substrings containing a list of
 * words, within a given string
 * @s: string to scan
 * @words:  array of words all substrings must be a concatenation
 * arrangement of
 * @nb_words: number of elements in the array words
 * @n: address at which to store the number of elements in the returned array
 *
 * Return:  an allocated array, storing each index in s, at which a
 * substring was found. If no solution is found, NULL is returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, k, count, str_len, words_len, check, cur_idx;
	int *array_idx, *match_idx;

	if (nb_words == 0 || !s || !words || !n)
		return (NULL);
	str_len = strlen(s);
	array_idx = malloc(str_len * sizeof(int));
	match_idx = malloc(nb_words * sizeof(int));
	if (!match_idx || !array_idx)
		return (NULL);
	words_len = strlen(words[0]);
	count = 0;
	for (i = 0; i <= str_len - nb_words * words_len; i++)
	{
		memset(match_idx, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				cur_idx = i + j * words_len;
				check = strncmp(s + cur_idx, *(words + k), words_len);
				if (!*(match_idx + k) && !check)
				{
					*(match_idx + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
		{
			*(array_idx + count) = i;
			count += 1;
		}
	}
	free(match_idx);
	*n = count;
	return (array_idx);
}