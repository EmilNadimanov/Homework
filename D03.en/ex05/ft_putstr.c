#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar (char c);

void ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}