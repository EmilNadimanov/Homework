#include <stdlib.h>
#include <unistd.h>

int strlength(char *str)
{
    int i;

    i = 0;
    while (*str++)
        i++;
    return i;
}

char   *ft_strdup(char *src)
{/*
    char *str;
    int i;
    int n;

    n = -1;
    i = strlength(src) + 1;
    str = malloc(i * sizeof(char));
    if (!str)
        return NULL;
    while (++n <= i)
        str[n] = src[n];
    return str;
}*/