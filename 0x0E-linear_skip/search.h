#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 * struct skiplist_t - linked list
 * @n:Integer stored
 * @index: Idx of the node
 * @express:Pointer to the next node
 * @next:pointer to the next node
 */
typedef struct skiplist_t
{
	int n;
	size_t index;
	struct skiplist_t *express;
	struct skiplist_t *next;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

#endif /* SEARCH_H */
