#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *dest, char *src)
{
    char *dest_copy;
    
    dest_copy = dest;
    while(*src != '\0')
    {
        *dest_copy = *src;
        dest_copy++;
        src++;
    }
    return dest;
}