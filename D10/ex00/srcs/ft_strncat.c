#include <stdlib.h>
#include <unistd.h>

char 		*ft_strncat(char *dest, char *src, int nb)
{
    char 	*input;

    input = dest;
    while (*input)
        input++;
    while (*src && nb > 0)
    {
        *input++ = *src++;
        nb--;
    }
    while (nb-- > 0)
        *input++ = '\0';
    return dest;
}
