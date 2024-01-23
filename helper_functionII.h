/**
 * node_head_swapper - Swap a node in a listint_t doubly-linked list.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list
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
