/*
Create a function that stores the program’s arguments within an array structure
and that returns the address of that array’s first box.
• All elements of the array must be processed, including av[0].
*/

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_par.h"
#include <stdio.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

void		ft_putnbr(int nb)
{
	char	digit;

	if (nb > -10 && nb < 10)
	{
		digit = (nb < 0) ? -1 * nb + '0' : (nb > 0) ? nb + '0': 48;
		if (nb < 0)
			ft_putchar(45);
		ft_putchar(digit);
	}
	else
	{
		digit = (nb >= 10) ? nb % 10 + '0' : -1 * (nb % 10) + '0';
		ft_putnbr(nb / 10);
		ft_putchar(digit);
	}
}

void		ft_show_tab(struct s_stock_par *par)
{
	int		i;
	int		j;

	i = -1;
	while (par[++i].str)
	{
		j = -1;
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		while (par[i].tab[++j])
			ft_putstr(par[i].tab[j]);
	}
}
