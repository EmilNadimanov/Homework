#include <stdlib.h>
#include <unistd.h>

int ft_is_prime(int nb)
{
    int check;
    
    check = 2;
    if (check > nb)
        return 0;
    while (check * check <= nb)
    {
        if (nb % check == 0)
            break;
        check++;
    }
    return (check * check > nb) ? 1 : 0;
}