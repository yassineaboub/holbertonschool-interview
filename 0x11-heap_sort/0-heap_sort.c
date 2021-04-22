#include "sort.h"

/**
 * swap - 2 element to swap
 * @array: array
 * @a: first element
 * @b: second element
 * @n: size of arr
 */
void swap(int *a, int *b, int *array, size_t n)
{

	int temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, n);
}

/**
 * heap - change array to heap maximum
 * @arr: array
 * @n: size of the array
 * @i: position
 * @size: array's size
 */
void heap(int *arr, int n, int i, size_t size)
{

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest], arr, size);
		heap(arr, n, largest, size);
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

	if (array == NULL)
		return;

	for (i = size / 2 ; i > 0; i--)
		heap(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i], array, size);

		heap(array, i, 0, size);
	}
}

