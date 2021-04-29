#ifndef SEARCH_ALGO_H
#define SEARCH_ALGO_H
#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
int advanced_binary_search(int *array, int value, int left, int right);
void print_search(const int *array, int left, int right);

#endif /*  SEARCH_ALGO_H */
