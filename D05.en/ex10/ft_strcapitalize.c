#include <stdlib.h>
#include <unistd.h>

char *ft_strcapitalize(char *str)
{
    int ch;
    int first_letter;

    ch = 0;
    first_letter = 1;
    while (str[ch])
    {
        if ((str[ch] >= 65 && str[ch] <= 90) || (str[ch] >= 97 && str[ch] <= 122)
            || (str[ch] >= 48 && str[ch] <= 57))
        {
            if (str[ch] >= 97 && str[ch] <= 122 && first_letter)
                str[ch] = str[ch] - 32;
            first_letter = 0;
        }
        else
            first_letter = 1;
        ch++;
    }
    return str;
}