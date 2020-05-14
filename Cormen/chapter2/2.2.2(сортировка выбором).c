//Code
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	int A[10] = {5,6,4,7,3,8,1,2,9,0};
	int i;
	int j;
	int min;
	int temp;

	i = 0;
	while (i < 9)
	{
		j = i;
		min = i;
		while (++j <= 9)
			if (A[j] < A[min])
				min = j;
		temp = A[i];
		A[i++] = A[min];
		A[min] = temp;
	}
	i = 0;
	while(i < 10)
		printf("%d\n", A[i++]);
}
//инвариант - все элементы по индексу от 0 до i упорядочены в возрастающем порядке, а максимальное число находится ближе к концу массива от i

//время = Theta(n^2)
//n-1        // 
//SIGMA n - i// так как всякий раз алгоритм оценивает и сравнивает каждый элемент по индексу от i до n - 1 
//i = 0      // и там, судя по всему, возникнет квадрат. Одному Богу известно, как разложить эту сигму в приемлемый вид.