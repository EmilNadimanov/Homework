#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_print_reverse_alphabet(void)
{
  int i = 122;
  while (i >= 97)
  {
    ft_putchar(i);
    i--;
  }
}