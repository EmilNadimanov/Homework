#include <stdlib.h>
#include <unistd.h>

int ft_str_is_uppercase(char *str)
{
    int ch;

    ch = 0;
    while (str[ch])
    {
        if (str[ch] < 65 || str[ch] > 90)
            return 0;
        ch++;
    }
    return 1;
}