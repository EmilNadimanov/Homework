#include <stdlib.h>
#include <unistd.h>

int ft_fibonacci(int index)
{
    if (index <= 0)
        return 0;
    else
        return (index == 1) ? 1 : ft_fibonacci(index-1) + ft_fibonacci(index-2);
}