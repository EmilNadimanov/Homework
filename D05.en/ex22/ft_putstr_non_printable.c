#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c);

void print_hex(int hex)
{
    char hexbase[17] = "0123456789abcdef";

    if (hex < 16)
        ft_putchar (hexbase[hex]);
    else
    {
        print_hex(hex / 16);
        ft_putchar(hexbase[hex % 16]);
    }
    return;
}

void ft_putstr_non_printable(char *str)
{
    int ch;

    ch = -1;
    while (str[++ch])
    {    
        if (str[ch] > 0 && str[ch] < 32)
        {
            ft_putchar('\\');
            if (str[ch] < 16)
                ft_putchar('0');
            print_hex(str[ch]);
            continue;
        }
        ft_putchar(str[ch]);
    }
    return;
}