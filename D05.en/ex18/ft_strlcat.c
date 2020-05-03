#include <stdlib.h>
#include <unistd.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    char *dest_copy;
    char *src_copy;
    int free_space;
    
    free_space = size;
    dest_copy = dest;
    src_copy = src;
    while (*dest_copy)
        dest_copy++;
    free_space = size - (dest_copy - dest) - 1;
    while (*src_copy)
    {
        if (free_space > 0)
        {
            *dest_copy = *src_copy;
            free_space--;
        }
        src_copy++;
        dest_copy++;
    }
    if (free_space < 0)
        return size + src_copy - src;
    *dest_copy = '\0';
    return (free_space > 0) ? dest_copy - dest : dest_copy - dest;
}