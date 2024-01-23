#include "sort.h"
#include "helper_function.h"

/**
 * quick_sort - Sort an proccessed array 
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
{
return;
}
lomuto_algo_sort(array, size, 0, size - 1);
}
