#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    char *dest_copy;
    char *src_copy;
    
    dest_copy = dest;
    src_copy = src;
    while (n != 0)
    {
        if (*src_copy != '0')
        {
            *dest_copy = *src_copy;
            dest_copy++;
            src_copy++;
        }
        else
        {
            while (n != 0)
                *dest_copy++ = '\0';
        }        
        n--;
    }
    return dest;
}