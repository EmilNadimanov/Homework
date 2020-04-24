#include <stdlib.h>
#include <unistd.h>

int ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return 0;
    else
        return (power == 0) ? 1 : nb * ft_recursive_power(nb, --power);
}