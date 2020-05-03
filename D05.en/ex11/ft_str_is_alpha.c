#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_str_is_alpha(char *str)
{
    int ch;

    ch = 0;
    while (str[ch])
    {
        if ((str[ch] >= 48 && str[ch] <= 57) ||
        (str[ch] >= 65 && str[ch] <= 90) ||
        (str[ch] >= 97 && str[ch] <= 122))
            ch++;
        else
            return 0;
    }
    return 1;
}