#include "sort.h"
#include "helper_function.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
#include "counting_sort_holder.h"
counter = malloc(sizeof(int) * (get_max + 1));
if (counter == NULL)
{
free(sort_true);
return;
}
for (k = 0; k <= get_max; k++)
{
counter[k] = 0;
}
for (k = 0; k < (int)size; k++)
{
counter[array[k]]++;
}
for (k = 1; k <= get_max; k++)
{
counter[k] += counter[k - 1];
}
print_array(counter, get_max + 1);
for (k = size - 1; k >= 0; k--)
{
sort_true[counter[array[k]] - 1] = array[k];
counter[array[k]]--;
}
for (k = 0; k < (int)size; k++)
{
array[k] = sort_true[k];
}
free(sort_true);
free(counter);
}
