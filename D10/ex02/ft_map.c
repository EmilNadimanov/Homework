#include <stdlib.h>
#include <unistd.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *result;

	i = -1;
	result = malloc(sizeof(int) * length);
	if (!result)
		return NULL;
	while (++i < length)
		result[i] = f(tab[i]);
	return result;
}
