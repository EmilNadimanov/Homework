#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strrev(char *str)
{
    int count_chars;
    int index_start;
    int index_end;
    char temp;
    index_start = 0;
    count_chars = 0;
    while (*(str + count_chars) != '\0')
    {
        count_chars++;
        index_end = count_chars - 1;
    }    
    if (count_chars <= 1)
        return str;
    else
    {
        while (index_start < count_chars / 2)
        {
            temp = str[index_start];
            str[index_start] = str[index_end];
            str[index_end] = temp;
            index_start++;
            index_end--;
        }
        return str;
    }
}