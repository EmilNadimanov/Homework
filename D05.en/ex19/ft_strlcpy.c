#include <stdlib.h>
#include <unistd.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int free_space;
	char *src_copy;
	char *dest_copy;

	dest_copy = dest;
	src_copy = src;
	free_space = size - 1;
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
	*dest_copy = '\0';
    return src_copy - src;
}