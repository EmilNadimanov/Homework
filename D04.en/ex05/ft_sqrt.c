#include <stdlib.h>
#include <unistd.h>

int ft_sqrt(int nb)
{
    long long int root;
    int check_loop;

    root = 1;
    if (nb == 0)
        return 0;
    while (root * root != nb)
    {
        printf("%d \t", root);
        root = (root + nb / root) / 2;
        if (check_loop == root - 1 || check_loop == root)
            return 0;
        check_loop = root;
    }
    return (nb % root == 0) ? (int)root : 0;
}