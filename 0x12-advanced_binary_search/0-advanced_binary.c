#include "search_algos.h"

/**
 * print - Print array
 * @array: The printed array
 * @left: start index
 * @right: end index
 */
void print_search(const int *array, int left, int right)
{
int i;
printf("Searching in array: ");
for (i = left; i <= right; i++)
{
if (i > left)
printf(", ");
printf("%d", array[i]);
}
printf("\n");
}

/**
* adv_binary - function to search
* @array: a pointer to the first element
* @left: index of first element
* @right: index of last element
* @value: the value to search for
* Return: return the index where value is located else return -1
**/
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);
return (advanced_binary_search(array, value, 0, size - 1));
}
/**
 * advanced_binary - Prints integers in the array
 * @array: array where to search the value
 * @size: size of the array
 * @value: the value to search for
 * Return: return the index where value is located else return -1
 */
int advanced_binary_search(int *array, int value, int left, int right)
{
int size_tmp, middle;
if ((abs(left) - abs(right)) == 0)
return (-1);
size_tmp = ((abs(right) - abs(left)) / 2) + 1;
middle = (left + right) / 2;
print_search(array, left, right);
if (array[middle] == value)
{
if (size_tmp <= 2)
return (middle);
else
return (advanced_binary_search(array, value, left, middle));
}
else if (array[middle] < value)
{
return (advanced_binary_search(array, value, middle + 1, right));
}
else if (array[middle] > value)
{
return (advanced_binary_search(array, value, left, middle));
}
return (-1);
}
