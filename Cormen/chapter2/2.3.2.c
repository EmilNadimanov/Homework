//сортировка слиянием без сигнального элемента
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void merge (int *A, int p, int q, int r)
{
	int j;
	int i;
	int *R;
	int *L;

	i = 0;
	j = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	L = malloc((n1) * sizeof(int));
	R = malloc((n2) * sizeof(int));
	while (i < n1)
		L[i] = A[p + i++];
	while (j < n2)
		R[j] = A[q + 1 + j++];
	i = 0;
	j = 0;
	while (p <= r)
    {
		if ((L[i] <= R[j] || j == n2) && i != n1)
			A[p++] = L[i++];
		if ((R[j] < L[i] || i == n1) && j != n2)
			A[p++] = R[j++];
	}
}

void merge_sort (int *A, int p, int r)
{
	int q;

	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A,p,q,r);
	}
	else
		return;
}

int main(void)
{
	int A[5] = {38,26,3,49,1};
	int i = 0;
	printf("Array A consists of: ");
	while(i < 5)
		printf("%d\t", A[i++]);
	merge_sort(A, 0, 4);
	printf("\nAnd if it's sorted:  ");
	i = 0;
	while(i < 5)
		printf("%2d\t", A[i++]);
	printf("\n");
	return 0;
}