#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find)
{
    int counter;
    int found;

    counter = -1;
    found = 0;
    while (str[++counter] != '\0')
    {
        if (str[counter] == to_find[0])
        {
            while (to_find[found] != '\0')
            {
                if (str[counter + found] == to_find[found])
                    found++;
                else
                {
                    found = 0;
                    break;
                }
            }
            if (to_find[found] == '\0')
                return str + counter;
        }
    }
    return (to_find[0] == '\0') ? str : "(null)";
}
