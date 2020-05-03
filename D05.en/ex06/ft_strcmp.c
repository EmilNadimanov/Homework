#include <stdlib.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    int count;
    
    count = 0;
    while (1)
    {
        if (s1[count] == s2[count])
        {
            if (s1[count++] == '\0')
                return 0;
            else
                continue;
        }
        if (s1[count] > s2[count])
            return 1;
        else
            return -1;
    }
}