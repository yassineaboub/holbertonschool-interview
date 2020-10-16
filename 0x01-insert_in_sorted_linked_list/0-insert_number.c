#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Pointer to the first node of the list.
 * @number: Integer value in the  new node
 * Return: number of nodes or NULL if it fails
*/


listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;
        current = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;


    if (*head == NULL || (*head)->n >= new_node->n) {
        new_node->next = *head;
        *head = new_node;
    }
    else {

        while (current->next != NULL && new_node->n > current->next->n) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return new_node;
}
