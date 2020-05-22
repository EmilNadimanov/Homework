#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_count_if(char **tab, int(*f)(char*))
{
    int result;

    result = 0;
    while (*tab)
        if (f(*tab++))
            result++;
    return result;
}
