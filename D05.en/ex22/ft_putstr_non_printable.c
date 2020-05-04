#include <stdlib.h>
#include <unistd.h>

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
    unsigned char *string;

    string = (unsigned char*)str;
    ch = -1;
    while (string[++ch])
    {
        if (string[ch] < 32 || string[ch] >= 127)
        {
            ft_putchar('\\');
            if (string[ch] < 16)
                ft_putchar('0');
            print_hex(string[ch]);
            continue;
        }
        ft_putchar(string[ch]);
    }
    return;
}
