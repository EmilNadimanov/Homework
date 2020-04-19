#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void ft_print_comb2(void)
{
    int d1 = 48;
	int d2 = 48;
	int d3 = 48;
	int d4 = 48;
	while (d1 >= 48 && d1 <= 57)
	{
		d2 = 48;
		while (d2 >= 48 && d2 <= 57)
		{
			d3 = 48;
			while (d3 >= 48 && d3 <= 57)
			{
				d4 = 48;
				while (d4 >= 48 && d4 <= 57)
				{
					if  (d1 < d3 || (d1 == d3 && d2 < d4)) 
					{
						ft_putchar(d1);
						ft_putchar(d2);	
						ft_putchar(32); 
						ft_putchar(d3);
						ft_putchar(d4);
						ft_putchar(44); 
						ft_putchar(32);
					}
					d4++;
				}
				d3++;
			}
			d2++;
		}
		d1++;
	}	
}