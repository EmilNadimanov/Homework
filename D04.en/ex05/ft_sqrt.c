#include <stdlib.h>
#include <unistd.h>

int ft_sqrt(int nb)
{
    int root;
    int check_loop;

    root = 1;
    while (root * root != nb)
    {
        root = (root + nb / root) / 2;
        if (check_loop == root - 1)
            return 0;
        check_loop = root;
    }
    return (nb % root == 0) ? root : 0;
}