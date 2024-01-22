#include "sort.h"
#include "helper_functon.h"

/**
 * selection_sort - Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
int *lowwer;
size_t k, l;
if (array == NULL || size < 2)
{
return;
}
for (k = 0; k < size - 1; k++)
{
lowwer = array + k;
for (l = k + 1; l < size; l++)
{
lowwer = (array[l] < *lowwer) ? (array + l) : lowwer;
}
if ((array + k) != lowwer)
{
swap_ints(array + k, lowwer);
print_array(array, size);
}
}
}
