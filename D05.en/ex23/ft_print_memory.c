#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c);

void    print_hex(int hex)
{
    char hexbase[17] = "0123456789abcdef";
    if (hex < 16)
    {
        ft_putchar (hexbase[hex]);
    }
    else
    {
        print_hex(hex / 16);
        ft_putchar(hexbase[hex % 16]);
    }
    return;
}

void    print_address(unsigned int lines, int size)
{
    int line_number;
    int address;
    int i;

    line_number = (size % 16) ? size / 16 + 1 - lines : size / 16 - lines;
    address = 16 * line_number;
    i = 7;
    while (address > 15)
    {
        i--;
        address /= 16;
    }
    while (i--)
        ft_putchar('0');
    address = 16 * line_number;
    print_hex (address);
    ft_putchar(':');
    ft_putchar(' ');        
}

void    print_numbers(unsigned char *addr_copy, int sizeleft)
{
    int pos;
    int count;
    int space;
    int shape;

    count = 16;
    pos = 0;
    space = 0;
    shape = 40;
    while (count-- && sizeleft--)
    {
        if ((int)*(addr_copy + pos) < 16)
            ft_putchar('0');
        print_hex((int)*(addr_copy + pos));
        shape -= 2;
        pos++;
        if (space++ == 1)
        {
            ft_putchar(' ');
            space = 0;
            shape--;
        }
    }
    while (shape--)
        ft_putchar(' ');
}

void    print_text(unsigned char* addr_copy, int sizeleft)
{
    int count;

    count = -1;
    while (++count < 16 && sizeleft--)
    {
        if (*(addr_copy + count) < 32 || *(addr_copy + count) > 126)
            ft_putchar('.');
        else
            ft_putchar(*(addr_copy + count));
    }
}

void    *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int lines;
    unsigned int chars;
    unsigned char *addr_copy;

    if (size == 0)
        return 0;
    chars = 0;
    lines = (size % 16) ? size / 16 + 1 : size / 16;
    while (lines)
    {
        print_address(lines, size);
        addr_copy = addr + chars;
        print_numbers(addr_copy, size - chars);
        print_text(addr_copy, size - chars);
        chars += 16;
        ft_putchar('\n');
        lines--;
    }
    return addr;
}