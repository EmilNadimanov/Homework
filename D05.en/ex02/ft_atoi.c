#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int number;
    int counter;
    int if_negative;

    if_negative = 0;
    number = 0;
    counter = 0;
    while (str[counter] != '\0')
    {
        if ((str[counter] >= '0' && str[counter] <= '9') 
            || str[counter] == '-' || str[counter] == '+')
        {   
            if (str[counter] == '-' || str[counter] == '+')
            {
                if_negative = (str[counter] == '-') ? 1 : 0;
                counter++;
            }
            else
                number = number * 10 + (int)(str[counter++] - 48);
        }
        else
            return (if_negative) ? -number : number;
    }
    return (if_negative) ? -number : number;
}