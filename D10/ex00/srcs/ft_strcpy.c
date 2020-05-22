#include <stdlib.h>
#include <unistd.h>

char *ft_strcpy(char *dest, char *src)
{
    char *dest_copy;
    
    dest_copy = dest;
    while(1)
    {
        *dest_copy = *src++;
        if (*dest_copy++ == 0)
            break;
    }
    return dest;
}
