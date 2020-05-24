void		ft_putchar(char c);

void		ft_putnbr(int nb)
{
	char	digit;

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
			digit = nb + '0';
			ft_putchar(digit);
		}
	}
	else
	{
		digit = (nb >= 10) ? nb % 10 + '0' : -1 * (nb % 10) + '0';
		ft_putnbr(nb / 10);
		ft_putchar(digit);
	}
}
