#include <stdlib.h>
#include <unistd.h>

char *ft_strncat(char *dest, char *src, int nb)
{
    char *input;
    char *src_cpy;

    input = dest;
    src_cpy = src;
    while (*input)
        input++;
    while (*src_cpy && nb > 0)
    {
        *input++ = *src_cpy++;
        nb--;
    }
    while (nb-- > 0)
    {
        *++input = '\0';
    }
    return dest;
}