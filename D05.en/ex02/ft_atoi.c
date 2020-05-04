#include <stdlib.h>
#include <unistd.h>

int ft_atoi(char *str)
{
    int number;
    int count;
    int if_negative;

    if_negative = 0;
    number = 0;
    count = 0;
    while (str[count] != '\0')
    {
        if ((str[count] >= '0' && str[count] <= '9')
            || str[count] == '-' || str[count] == '+' || str [count] < 33)
        {   
            if (str[count] == '-' || str[count] == '+' || str [count] < 33)
            {
                if_negative = (str[count] == '-') ? 1 : 0;
                count++;
            }
            else
                number = number * 10 + (int)(str[count++] - 48);
        }
        else
            return (if_negative) ? -number : number;
    }
    return (if_negative) ? -number : number;
}
