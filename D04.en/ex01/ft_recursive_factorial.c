#include <stdlib.h>
#include <unistd.h>

int ft_recursive_factorial(int nb)
{
    long long result;

    result = nb;
    if (result == 0 || result == 1)
        return 1;
    if (result > 1)
    {
        result *= ft_recursive_factorial(result - 1);
        if (result > 2147483647)
            return 0;
        else
            return (int)result;    
    }
    else
        return 0;
}