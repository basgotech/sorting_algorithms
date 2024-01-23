#include "sort.h"
#include "helper_function.h"

/**
 * merge_sort - Sorts an array of integers in ascending.
 * order using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description:
 * - This function sorts the given array using
 * the top-down merge sort algorithm.
 * - It divides the array into two halves,
 * sorts each half recursively, and then merges them.
 * - The merging is done using the merge_div_arr function.
 * - The time complexity of this function is O(n log n),
 * where n is the size of the array.
 * - Uses a temporary buffer array (buffer_getter) for merging.
 * - This function serves as the entry point for the merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
int *buffer_get;

if (array == NULL || size < 2)
{
return;
}
buffer_get = malloc(sizeof(int) * size);
if (buffer_get == NULL)
{
return;
}
rec_merge_sort(array, buffer_get, 0, size);
free(buffer_get);
}
