#include <stdlib.h>
#include <unistd.h>

int ft_iterative_factorial(int nb)
{
    long long int result;
    
    result = nb;
    if (nb == 0 || nb == 1)
        return 1;
    else if (nb < 0)
        return 0;
    else
    {
        while (nb > 1)
            result *= --nb;            
    }
    if (result > 2147483647)
        return 0;
    else
        return (int)result;
}