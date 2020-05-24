#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
• Create the function ft_map which, for a given ints array, applies a function on all
elements of the array (in ordre) and returns a array of all the return values. This
function will be applied following the array’s order
*/
int 		*ft_map(int *tab, int length, int(*f)(int))
{
	int 	i;
	int 	*result;

	i = -1;
	result = malloc(sizeof(int) * length);
	if (!result)
		return NULL;
	while (++i < length)
		result[i] = f(tab[i]);
	return result;
}

int inc_num(int n)
{
	return n + 5;
}

int main()
{
	int test1[] = {1,2,3,4,5};

	int* res = ft_map(test1, 5, inc_num);
	for (int i = 0; i < 5; i++)
		printf("%d,", res[i]);
	printf("\n");

	free(res);

	int test2[] = {-25,0,20,45};

	res = ft_map(test2, 3, inc_num);
	for (int i = 0; i < 3; i++)
		printf("%d,", res[i]);
	printf("\n");

	free(res);

	int test3[] = {5};

	res = ft_map(test3, 0, inc_num);
	for (int i = 0; i < 0; i++)
		printf("%d,", res[i]);
	printf("\n");
	
	free(res);

}