#include <stdlib.h>
#include <unistd.h>

char *ft_strupcase(char *str)
{
    int ch;

    ch = 0;
    while (str[ch])
    {
        if (str[ch] >= 97 && str[ch] <= 122)
        {
            str[ch] = str[ch] - 32;
            ch++;
        }
        else
            ch++;        
    }
    return str;
}
