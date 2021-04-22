#include "sort.h"

/**
 * swap - 2 element to swap
 * @array: array
 * @a: first element index
 * @b: econd element index
 */
void swap(int *array, int a, int b)
{
	if (a == b)
		return;
	array[a] ^= array[b];
	array[b] ^= array[a];
	array[a] ^= array[b];
}

/**
 * heap - change array to heap maximum
 * @array: array
 * @heap_size: size of the array
 * @i: recursive element
 * @size: array's size
 */
void heap(int *array, size_t heap_size, size_t i, size_t size)
{
	size_t largest = i;
	size_t l = 2 * i + 1, r = 2 * i + 2;

	if (l < heap_size && array[l] > array[largest])
		largest = l;
	if (r < heap_size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap(array, i, largest);
		print_array(array, size);
		heap(array, heap_size, largest, size);
	}
}

/**
 * heap_sort - sort array
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 - 1; i > 0; i--)
		heap(array, size, i, size);
	heap(array, size, 0, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		heap(array, i, 0, size);
	}
}
