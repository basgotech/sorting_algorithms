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
