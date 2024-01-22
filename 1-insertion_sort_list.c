#include "sort.h"

void node_swapper(listint_t **header, listint_t **fnode, listint_t *snode);

/**
 * insertion_sort_list - Sorts a doubly linked list of int
 * @list: A pointer to the head of a doubly-linked list of int.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *getter, *tempper, *insert;
if (list == NULL || *list == NULL || (*list)->next == NULL)
{
return;
}
for (getter = (*list)->next; getter != NULL; getter = tempper)
{
tempper = getter->next;
insert = getter->prev;
while (insert != NULL && getter->n < insert->n)
{
node_swapper(list, &insert, getter);
print_list((const listint_t *)*list);
}
}
}

/**
 * node_swapper - Swap two nodes.
 * @header: A pointer to the head of the doubly-linked list.
 * @fnode: A pointer to the first node to swap.
 * @snode: The second node to swap.
 */
void node_swapper(listint_t **header, listint_t **fnode, listint_t *snode)
{
(*fnode)->next = snode->next;
if (snode->next != NULL)
{
snode->next->prev = *fnode;
}
snode->prev = (*fnode)->prev;
snode->next = *fnode;
if ((*fnode)->prev != NULL)
{
(*fnode)->prev->next = snode;
}
else
{
*header = snode;
}
(*fnode)->prev = snode;
*fnode = snode->prev;
}
