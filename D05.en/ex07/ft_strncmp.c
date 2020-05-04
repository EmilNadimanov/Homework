#include <stdlib.h>
#include <unistd.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int count;
    
    count = 0;
    if (n == 0)
        return 0;
    while (count < n)
    {
        if (s1[count] == s2[count])
        {
            count++;
            continue;
        }
        return (s1[count] > s2[count]) ? 1 : -1;
    }
    return 0;
}
