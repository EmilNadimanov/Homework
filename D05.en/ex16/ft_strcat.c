#include <stdlib.h>
#include <unistd.h>

char *ft_strcat(char *dest, char *src)
{
    char *input;
    char *src_cpy;
    
    src_cpy = src;
    input = dest;    
    while (*input)
        input++;
    while (*src_cpy)
        *input++ = *src_cpy++;
    return dest;
}