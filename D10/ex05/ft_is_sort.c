#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
Create a function ft_is_sort which returns 1 if the array is sorted and 0 if it isn’t.
The function given as argument should return a negative integer if the first argument
is lower than the second, 0 if they’re equal or a positive integer for anything else.
*/
int 		ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int 	i;

	i = -1;
	if (length == 1)
		return 1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			return 0;
	return 1;
}

int cmpnbr(int a, int b)
{
	return a - b;
}

int main(int argc, char** argv)
{
	if (argc < 1)
		return 0;
	int test[argc - 1];
	for (int i = 1; i < argc; i++)
		test[i - 1] = atoi(argv[i]);
	
	printf("%d", ft_is_sort(test, argc - 1, cmpnbr));
}