#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i;
    count = 0;
    while (*(str + count) != '\0')
        count++;
    return count;
}