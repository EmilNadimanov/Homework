#include <stdlib.h>
#include <unistd.h>

char *ft_strcapitalize(char *str)
{
    int c;
    int first_char;

    c = 0;
    first_char = 1;
    while (str[c])
    {
        if ((str[c] >= 65 && str[c] <= 90) || (str[c] >= 97 && str[c] <= 122)
            || (str[c] >= 48 && str[c] <= 57))
        {
            if (first_char)
                str[c] = (str[c] >= 97 && str[c] <= 122) ? str[c] - 32 : str[c];
            else
                str[c] = (str[c] >= 65 && str[c] <= 90) ? str[c] + 32 : str[c];
            first_char = 0;
        }
        else
            first_char = 1;
        c++;
    }
    return str;
}
