#include <stdlib.h>
#include <unistd.h>

int    *ft_range(int min, int max)
{
	int *numarr;
	int i;

	if (min >= max)
		return NULL;
	i = 0;
	numarr = malloc((max - min) * sizeof(int));
    if (!numarr)
		return NULL;
	while (i < max++ - min)
		numarr[i++] = min++;
	return numarr;
}