#include <stdlib.h>
#include <unistd.h>

int ft_iterative_power(int nb, int power)
{
    int result;

    result = 1;
    if (power < 0)
        return 0;
    else
    {
        while (power-- > 0)
            result *= nb;
        return result;
    }
}