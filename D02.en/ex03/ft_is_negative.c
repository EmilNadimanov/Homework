#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar(78);
	else
		ft_putchar(80);
}