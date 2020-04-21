#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_ultimate_div_mod(int *a, int *b)
{
    int param_a;
    param_a = *a;
    int param_b;
    param_b = *b;
    *a = param_a / param_b;
    *b = param_a % param_b;
}