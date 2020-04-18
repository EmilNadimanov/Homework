#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void ft_putnbr(int nb)
{
	int nb_copy = nb;
	int nb_reversed = 0;
	char digit;
	while (nb_copy != 0)
		{
			nb_reversed *= 10;
			nb_reversed = nb_reversed + nb_copy%10;
			nb_copy /= 10;						
		}	
	while (nb_reversed != 0)
		{
			digit = nb_reversed%10 + '0';
			ft_putchar(digit);
			nb_reversed /= 10;
		}
}

int main()
{
	int n;
	scanf ("%d", &n);
    ft_putnbr(n);
	return 0;
}
