#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //faaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

int ft_sqrt(int nb)
{
    long long int root;
    int check_loop;

    root = 1;
    if (nb == 0)
        return 0;
    while (root * root != nb)
    {
        root = (root + nb / root) / 2;
        if (check_loop == root - 1 || check_loop == root)
            return 0;
        check_loop = root;
    }
    return (nb % root == 0) ? (int)root : 0;
}