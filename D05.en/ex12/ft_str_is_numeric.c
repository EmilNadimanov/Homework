#include <stdlib.h>
#include <unistd.h>

int ft_str_is_numeric(char *str)
{
    int ch;

    ch = 0;
    while (str[ch])
    {
        if (str[ch] < 48 || str[ch] > 57)
            return 0;
        ch++;
    }
    return 1;
}
