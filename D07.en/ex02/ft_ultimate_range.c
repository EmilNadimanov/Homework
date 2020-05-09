#include <stdlib.h>
#include <unistd.h>

int    ft_ultimate_range(int **range, int min, int max)
{
    int *numarr;
    int i;

    if (min >= max)
    {
        *range = NULL;
        return 0;
    }
    i = 0;
    numarr = malloc((max - min) * sizeof(int));
    while (i < max++ - min)
        numarr[i++] = min++;
    *range = numarr;
    return i;
}