#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void ft_print_comb(void)
{
    int d1 = 48;
	int d2 = 48;
	int d3 = 48;
	while (d1 >= 48 && d1 <= 57)
	{
		d2 = 48;
		d3 = 48;
		while (d2 >= 48 && d2 <= 57)
		{
			d3 = 48;
			while (d3 >= 48 && d3 <= 57)
			{
				if (d1 != d2 && d1 != d3 && d2 != d3)
					{
					ft_putchar (d1);
					ft_putchar (d2);
					ft_putchar (d3);
					if (!(d1 == 57 && d2 == 56 && d3 == 55))
						ft_putchar(44);
					ft_putchar(32);
					}
				d3++;
			}
			d2++;
		}
		d1++;
	}
	
}

int main()
{
	ft_print_comb();
	return 0;
}
