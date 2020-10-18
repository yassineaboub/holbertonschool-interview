#include "lists.h"

/**
 * check_cycle - function that checks if
 * a singly linked list has a cycle in it
 * @list: Linked list
 * Return: return 1 if it has a cycle otherwise 0
 */
int check_cycle(listint_t *list)
{
listint_t *i = list, *j = list;

while (i && j)
{
if (!(j->next) || !(j->next->next))
break;
i = i->next;
j = j->next->next;
if (i == j)
return (1);
}
return (0);
}

