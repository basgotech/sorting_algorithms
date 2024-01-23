#include "sort.h"
#include "helper_function.h"

/**
 * heap_sort - Sorts an array of integers in ascending.
 * order using the Heap sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
int x;
if (array == NULL || size < 2)
{
return;
}
for (x = (size / 2) - 1; x >= 0; x--)
{
com_binery_hipper(array, size, size, x);
}
for (x = size - 1; x > 0; x--)
{
swapper(array, array + x);
print_array(array, size);
com_binery_hipper(array, size, x, 0);
}
}
