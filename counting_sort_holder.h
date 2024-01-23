int *counter, *sort_true, get_max, k;
if (array == NULL || size < 2)
{
return;
}
get_max = max_getter(array, size);
sort_true = malloc(sizeof(int) * size);
if (sort_true == NULL)
{
return;
}
