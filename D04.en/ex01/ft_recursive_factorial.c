#include <stdlib.h>
#include <unistd.h>

int ft_recursive_factorial(int nb)
{
    if (nb >= 0)
        return (nb == 0) ? 1 : nb * ft_recursive_factorial(nb - 1);
    else
        return 0;
}