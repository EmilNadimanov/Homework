#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void rush (int x, int y) //x - width, y - length;
{
    int symbol;
    int row;
    char ch;

    symbol = 0;
    row = 0;
    while (row++ < y)
    {
        if (row == 1 || row == y)
        {
            while (symbol++ < x)
                ft_putchar((symbol == 1 || symbol == x) ? 'o' : '-');
            if (row == 1 && y != 1)
                ft_putchar('\n');
            symbol = 0; 
        }
        else
        {
            while (symbol++ < x)
                ft_putchar((symbol == 1 || symbol == x) ? '|' : ' ');
            ft_putchar('\n');
            symbol = 0;
        }     
    }
}