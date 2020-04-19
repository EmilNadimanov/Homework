#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

void ft_print_numbers(void)
{
	int i = 48;
	while (i <= 57)
	{
		ft_putchar(i);
		i++;
	}
}