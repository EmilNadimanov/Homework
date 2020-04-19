#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void ft_putnbr(int nb)
{
	char digit;

	if (nb > -10 && nb < 10)
	{
		if (nb < 0)
		{
			digit = -1 * nb + '0';
			ft_putchar(45);
			ft_putchar(digit);
		}
		else  
		{
			if (nb > 0)
				digit = nb + '0';
			else digit = 48;
				ft_putchar(digit);
		}
	}
	else
	{
		if (nb >= 10)
			digit = nb % 10 + '0';
		else
			digit = -1 * (nb % 10) + '0';
		ft_putnbr(nb / 10);
		ft_putchar(digit);
	}
}

int main ()
{
	ft_putnbr(-2147483648);
	return 0;
}