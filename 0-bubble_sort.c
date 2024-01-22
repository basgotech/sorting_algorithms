#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int swapper, temp;

if (array == NULL || size < 2)
{
return;
}
for (i = 0; i < size - 1; i++)
{
swapper = 0;
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
swapper = 1;
print_array(array, size);
}
}
if (swapper == 0)
{
break;
}
}
}
