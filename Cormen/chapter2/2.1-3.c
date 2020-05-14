//Задача поиска
//Нашёл v - верни индекс, иначе верни NIL
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int A[6] = {31,41,59,26,41,58};
    int i;
    int v = 213;
    int found;

    found = 0;
    i = -1;
    while (++i < 6)
    {
        if (v == A[i])
        {
            printf("Index i, where v = A[i] is %d\n", i);
            found++;
        }            
    }
    if (!found)
        printf("NIL\n");
    return 0;
}