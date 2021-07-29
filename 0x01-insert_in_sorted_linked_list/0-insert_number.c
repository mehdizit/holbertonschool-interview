#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * function that inserts a number into a sorted singly linked list
 * @head: header node
 * @number: node's new number
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *prev, *next, *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	prev = *head;
	next = prev->next;
	while (prev)
	{
		if (prev->n >= number)
		{
			new->next = prev;
			*head = new;
			return (new);
		}
		else if (!next && prev->n <= number)
		{
			prev->next = new;
			new->next = NULL;
			return (new);
		}
		else if (prev->n <= number && next->n >= number)
		{
			prev->next = new;
			new->next = next;
			return (new);
		}
		prev = next;
		next = prev->next;
	}
	return (NULL);
}
