#include <stdlib.h>
#include <unistd.h>

int ft_recursive_power(int nb, int power)
{
    long long int result;

    result = nb;
    if (power >= 0)
        if (power == 0)
            return 1;
        else
        {
            result *= ft_recursive_power(result, --power);
            if (result > 2147483647)
                return 0;
            else
                return (int)result; 
        }
    else
        return 0;
}