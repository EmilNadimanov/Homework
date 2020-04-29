#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void rush (int x, int y) //x - width, y - length;
{
    int symbol;
    int row;

    symbol = 0;
    row = 0;
    while (row++ < y)
    {
        if (row == 1)
        {
            while (symbol++ < x)
                ft_putchar((symbol == 1) ? 'A' : (symbol == x) ? 'C' : 'B');
            if (y != 1)
                ft_putchar('\n');
            symbol = 0; 
        }
        else
            if (row == y)
            {
                while (symbol++ < x)
                    ft_putchar((symbol == 1) ? 'C' : (symbol == x) ? 'A' : 'B');
                symbol = 0; 
            }
            else
            {
                while (symbol++ < x)
                    ft_putchar((symbol == 1 || symbol == x) ? 'B' : ' ');
                ft_putchar('\n');
                symbol = 0;
            }     
    }
}