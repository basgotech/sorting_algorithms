#include "sort.h"
#include "helper_functionII.h"

/**
 * cocktail_sort_list - Sorts a doubly linked
 * list of integers in ascending order
 *  using the Cocktail Shaker sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */

void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker_algo;
bool sns = false;

if (list == NULL || *list == NULL || (*list)->next == NULL)
{
return;
}

for (tail = *list; tail->next != NULL;)
{
tail = tail->next;
}
while (sns == false)
{
sns = true;
for (shaker_algo = *list; shaker_algo != tail; shaker_algo = shaker_algo->next)
{
if (shaker_algo->n > shaker_algo->next->n)
{
node_head_swapper(list, &tail, &shaker_algo);
print_list((const listint_t *)*list);
sns = false;
}
}
for (shaker_algo = shaker_algo->prev; shaker_algo != *list;
shaker_algo = shaker_algo->prev)
{
if (shaker_algo->n < shaker_algo->prev->n)
{
node_behind_swapper(list, &tail, &shaker_algo);
print_list((const listint_t *)*list);
sns = false;
}
}
}
}
