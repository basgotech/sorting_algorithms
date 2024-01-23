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
