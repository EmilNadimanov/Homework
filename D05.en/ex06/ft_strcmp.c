#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2++)
    {
        if (*s1++ == 0)
            return 0;
    }
    return (*s1 - *--s2);
}
