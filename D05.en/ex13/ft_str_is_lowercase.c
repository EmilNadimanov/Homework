#include <stdlib.h>
#include <unistd.h>

int ft_str_is_lowercase(char *str)
{
    int ch;

    ch = 0;
    while (str[ch])
    {
        if (str[ch] < 97 || str[ch] > 122)
            return 0;
        ch++;
    }
    return 1;
}
