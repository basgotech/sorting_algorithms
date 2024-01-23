/**
 * node_head_swapper - Swap a node in a listint_t doubly-linked list
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_algo: A pointer to the current swapping node of the cocktail shaker algorithm.
 */
void node_head_swapper(listint_t **list, listint_t **tail, listint_t **shaker_algo)
{
listint_t *tempo_holder = (*shaker_algo)->next;
if ((*shaker_algo)->prev != NULL)
{
(*shaker_algo)->prev->next = tempo_holder;
}
else
{
*list = tempo_holder;
}
tempo_holder->prev = (*shaker_algo)->prev;
(*shaker_algo)->next = tempo_holder->next;
if (tempo_holder->next != NULL)
{
tempo_holder->next->prev = *shaker_algo;
}
else
{
*tail = *shaker_algo;
}
(*shaker_algo)->prev = tempo_holder;
tempo_holder->next = *shaker_algo;
*shaker_algo = tempo_holder;
}

/**
 * node_behind_swapper - Swap a node in a listint_t doubly-linked
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_algo: A pointer to the current swapping node of the cocktail shaker algo.
 */
void node_behind_swapper(listint_t **list, listint_t **tail, listint_t **shaker_algo)
{
listint_t *tempo_holder = (*shaker_algo)->prev;
if ((*shaker_algo)->next != NULL)
{
(*shaker_algo)->next->prev = tempo_holder;
}
else
{
*tail = tempo_holder;
}
tempo_holder->next = (*shaker_algo)->next;
(*shaker_algo)->prev = tempo_holder->prev;
if (tempo_holder->prev != NULL)
{
tempo_holder->prev->next = *shaker_algo;
}
else
{
*list = *shaker_algo;
}
(*shaker_algo)->next = tempo_holder;
tempo_holder->prev = *shaker_algo;
*shaker_algo = tempo_holder;
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
