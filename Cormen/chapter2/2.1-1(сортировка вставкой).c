//INSERTION-SORT Сортировка вставками
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int A[6] = {31,41,59,26,41,58};
    int j;
    int i;

    j = 1;
    while (j < 6)
    {
        int key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
            A[i + 1] = A[i--];
        A[i + 1] = key;
        j++;
    }
    return 0;
}