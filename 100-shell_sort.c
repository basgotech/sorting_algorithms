#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
int gap = 1, i;

while (gap < (int)size / 3)
{
gap = gap * 3 + 1;
}
while (gap > 0)
{
for (i = gap; i < (int)size; i++)
{
int temp = array[i];
int j = i;
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}

array[j] = temp;
}
print_array(array, size);
gap = (gap - 1) / 3;
}
}
