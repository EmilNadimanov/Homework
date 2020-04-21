#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_sort_integer_table(int *tab, int size)
{
    int temp;
    int to_compare;
    int compare_with;
    to_compare = 0;
    compare_with = 0;
    while (to_compare < size)
    {
        while (compare_with < size)
        {
            if (tab[to_compare] > tab[compare_with])
            {
                temp = tab[to_compare];
                tab[to_compare] = tab[compare_with];
                tab[compare_with] = temp;
            }
            compare_with++;
        }
        to_compare++;
        compare_with = to_compare + 1;
    }
}