#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_find_next_prime(int nb)
{
    int nextprime;
    int check_divisor;

    nextprime = nb;
    while (1)
    {
        check_divisor = 2;
        if (check_divisor > nextprime)
        {
            nextprime++;
            continue;
        }
        while (check_divisor * check_divisor <= nextprime)
        {
            if (nextprime % check_divisor == 0)
            {
                nextprime++;
                check_divisor = 2;
                continue;
            }
            check_divisor++;
        }
        if (check_divisor * check_divisor > nextprime)
        {
            printf ("%d", check_divisor);
            return nextprime;
        }
        nextprime++;
    }
}