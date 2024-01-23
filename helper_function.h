/**
 * swapper - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swapper(int *a, int *b)
{
int tempo;
tempo = *a;
*a = *b;
*b = tempo;
}

/**
 * lomuto_algo_part - Order a subset of an array of integers
 * @array: The array of integers.
 * @size: The size of the array.
 * @left_arr: The starting index of the subset to order.
 * @right_arr: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_algo_part(int *array, size_t size, int left_arr, int right_arr)
{
int *pivot, lower, upper;
pivot = array + right_arr;
for (upper = lower = left_arr; lower < right_arr; lower++)
{
if (array[lower] < *pivot)
{
if (upper < lower)
{
swapper(array + lower, array + upper);
print_array(array, size);
}
upper++;
}
}
if (array[upper] > *pivot)
{
swapper(array + upper, pivot);
print_array(array, size);
}
return (upper);
}



/**
 * merge_div_arr - Merges two divided arrays into a single array.
 * @div_arr: The original array to be merged.
 * @buffer_getter: A buffer array used for merging.
 * @first: The starting index of the first sub-array.
 * @center: The ending index of the first sub-array and the starting index of the second sub-array.
 * @end: The ending index of the second sub-array.
 *
 * Description:
 * - This function merges two divided arrays into a single sorted array.
 * - The two sub-arrays to be merged are [first, center) and [center, end) in div_arr.
 * - The buffer_getter array is used as a temporary buffer for merging.
 * - The function assumes that the two sub-arrays are already sorted.
 * - The time complexity of this function is O(end - first).
 * - This function is designed for use in a top-down merge sort algorithm.
 */
void merge_div_arr(int *div_arr, int *buffer_getter, size_t first, size_t center,
		size_t end)
{
size_t x, y, z = 0;
printf("Merging...\n[left]: ");
print_array(div_arr + first, center - first);
printf("[right]: ");
print_array(div_arr + center, end - center);
for (x = first, y = center; x < center && y < end; z++)
{
buffer_getter[z] = (div_arr[x] < div_arr[y]) ? div_arr[x++] : div_arr[y++];
}
for (; x < center; x++)
{
buffer_getter[z++] = div_arr[x];
}
for (; y < end; y++)
{
buffer_getter[z++] = div_arr[y];
}
for (x = first, z = 0; x < end; x++)
{
div_arr[x] = buffer_getter[z++];
}
printf("[Done]: ");
print_array(div_arr + first, end - first);
}

/**
 * rec_merge_sort - Recursively sorts a divided array using the merge sort algorithm.
 * @div_arr: The array to be sorted.
 * @buffer_getter: A buffer array used for merging.
 * @first: The starting index of the sub-array to be sorted.
 * @end: The ending index of the sub-array to be sorted.
 *
 * Description:
 * - This function recursively applies the merge sort algorithm to sort a sub-array.
 * - The sorted sub-arrays are merged using the merge_div_arr function.
 * - The function uses the buffer_getter array as a temporary buffer for merging.
 * - The time complexity of this function is O(n log n), where n is the size of the sub-array.
 * - This function is designed for use in a top-down merge sort algorithm.
 */
void rec_merge_sort(int *div_arr, int *buffer_getter, size_t first, size_t end)
{
size_t mid;

if (end - first > 1)
{
mid = first + (end - first) / 2;
rec_merge_sort(div_arr, buffer_getter, first, mid);
rec_merge_sort(div_arr, buffer_getter, mid, end);
merge_div_arr(div_arr, buffer_getter, first, mid, end);
}
}




/**
 * lomuto_algo_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void lomuto_algo_sort(int *array, size_t size, int left, int right)
{
int p;

if (right - left > 0)
{
p = lomuto_algo_part(array, size, left, right);
lomuto_algo_sort(array, size, left, p - 1);
lomuto_algo_sort(array, size, p + 1, right);
}
}

/**
 * max_getter - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @get_size: The size of the array.
 * Return: The maximum integer in the array.
 */

int max_getter(int *array, int get_size)
{
int max_get, k;
for (max_get = array[0], k = 1; k < get_size; k++)
{
if (array[k] > max_get)
{
max_get = array[k];
}
}
return (max_get);
}
