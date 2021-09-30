#include "slide_line.h"

/**
 * reverse - reverse the list
 * @l: list
 * @size: size
 **/
void reverse(int *l, size_t size)
{
	size_t i, j;
	int t;

	for (i = 0, j = size - 1; i < size / 2; i++, j--)
	{
		t = l[i];
		l[i] = l[j];
		l[j] = t;
	}
}

/**
 * add - add
 * @l: list
 * @size: size
 **/
void add(int *l, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
		for (j = i + 1; j < size; j++)
		{
			if (l[i] != 0 && l[j] != 0 && l[i] != l[j])
			{
				i = j;
				break;
			}

			if (l[i] != 0 && l[i] == l[j])
			{
				l[i] += l[i];
				l[j] = 0;
				break;
			}
		}
}

/**
 * align - align
 * @l: list
 * @size: size
 **/
void align(int *l, size_t size)
{
	size_t i, j;

	for (i = 0, j = 0; i < size; i++)
		if (l[i] != 0)
		{
			l[j] = l[i];
			j++;
		}
	for (; j < size; j++)
		l[j] = 0;
}

/**
 * slide_line - slides and merges an array of integers
 * @line: list
 * @size: size
 * @direction: direction
 * Return: 1 or 0
 **/
int slide_line(int *line, size_t size, int direction)
{
	switch (direction)
	{
	case 0:
		add(line, size);
		align(line, size);
		break;
	case 1:
		reverse(line, size);
		add(line, size);
		align(line, size);
		reverse(line, size);
		break;
	default:
		return (0);
	}
	return (1);
}