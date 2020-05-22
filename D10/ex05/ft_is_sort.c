#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;

	i = -1;
	if (length == 1)
		return 1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			return 0;
	return 1;
}