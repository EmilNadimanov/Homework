#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c);

void ft_rev_params(int argc, char **argv, int i)
{
    char *arg;

    if (i < argc)
    {
        arg = argv[i++];
        ft_rev_params(argc, argv, i);
        while(*arg)
            ft_putchar(*arg++);
        ft_putchar('\n');
    }
    return;
}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    ft_rev_params(argc, argv, i);
    return 0;
}
