#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void ft_print_alphabet(void)
{
    int i = 97;
    while (i<=122)
        {
            ft_putchar(i);
            i++;
        }
}