#include <stdlib.h>
#include <unistd.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int free_space;
	char *src_copy;

	src_copy = src;
	free_space = size - 1;
    while (*src_copy)
    {
        if (free_space > 0)
		{
            *dest = *src_copy;
			free_space--;
        	dest++;
		}
        src_copy++;
    }
	*dest = (size == 0) ? *dest : '\0';
    return src_copy - src;
}
