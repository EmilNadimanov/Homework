#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_is_negative(int n)
{
    if (n < 0)
		ft_putchar(78);
    else 
		ft_putchar(80);
}

int main()
{
    int n;
	ft_is_negative(n);
	return 0;
}
