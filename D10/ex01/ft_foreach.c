#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
Create the function ft_foreach which, for a given ints array, applies a function on
all elements of the array. This function will be applied following the array’s order.
*/

void 		ft_foreach(int *tab, int length, void(*f)(int))
{
	int 	i;

	i = -1;
	while (++i < length)
		f(tab[i]);
}

void putnbr(int n)
{
	printf("%d,", n);
}

int main()
{
	int test1[] = {1,2,3,4,5};
	int test2[] = {-25,0,20,45};
	int test3[] = {5};
	
	ft_foreach(test1, 5, putnbr);
	printf("\n");
	ft_foreach(test2, 3, putnbr);
	printf("\n");
	ft_foreach(test3, 0, putnbr);
	printf("\n");
}