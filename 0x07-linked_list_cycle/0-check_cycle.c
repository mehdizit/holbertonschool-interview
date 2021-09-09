
#include <stdio.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - function that checks if a linked list has a cycle on it
 * @list: head of the list
 * Return: 1 if has a cycle or 0 if not
 */

int check_cycle(listint_t *list)
{
listint_t *turtle, *hare;

turtle = list;
hare = list;

if (list == NULL)
return (0);

while (turtle->next != NULL && hare->next != NULL)
{
turtle = turtle->next;
hare = hare->next->next;
if (hare == NULL)
break;
if (turtle == hare)
return (1);
}
return (0);
}