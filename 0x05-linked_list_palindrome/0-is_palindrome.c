#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindorme - function that checks if
 * a singly linked list is a palindrome
 * @head: linked list's head
 * Return: Return: 0 if it is not a palindrome, 1
**/
int is_palindrome(listint_t **head)
{
listint_t *i = *head;
int j = 0, l[10000], x;

if (!i)
return (1);
while (i)
{
l[j] = i->n;
j++;
i = i->next;
}
for (x = 0; x < j; x++)
{

if (x > j / 2 || l[x] != l[j - 1 - x])
break;
}
if (x <= j / 2)
return (0);
return (1);
}
