#include <stdlib.h>
#include <unistd.h>

char *ft_strlowcase(char *str)
{
    int ch;

    ch = 0;
    while (str[ch])
    {
        if (str[ch] >= 65 && str[ch] <= 90)
        {
            str[ch] = str[ch] + 32;
            ch++;
        }
        else
            ch++;        
    }
    return str;
}