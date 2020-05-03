#include <stdlib.h>
#include <unistd.h>

int checkbase(char *base)
{
    int s;
    int b;

    s = 0;
    b = 1;
    while (base[s])
    {
        if ((base[s] >= 65 && base[s] <= 90)
        || (base[s] >= 97 && base[s] <= 122)
        || (base[s] >= 48 && base[s] <= 57))
            s++;
        else
            return 1;
    }
    s = 0;
    while (base[s])
    {
        while (base[b])
        {
            if (base[s] == base [b++])
                return 1;
        }
        b = ++s + 1;
    }
    return 0;
}

int checkstring(char *str, char *base)
{
    int s;
    int b;
    int ch;

    s = 0;
    b = 0;
    ch = 0;
    while (str[s])
    {
        printf("Symbol %d is %c\n", s, str[s]);
        while (base[b])
        {
            if (str[s] == base [b++] || str[s] == '-' || str[s] == '+')
                ch = 1;
        }
        if (ch == 0)
            return 1;
        b = 0;
        ch = 0;
        s++;
    }
    return 0;
}

int mathpow (int number, int power)
{
    int copy;

    copy = number;
    while (power > 1)
    {
        number *= copy;
        power--;
    }
    return (power == 0) ? 1 : number;
}

int changetodec(char *str, char *base, int getbase)
{
    char* str_copy;
    int nbr;
    int i;
    int power;
    
    i = 0;
    nbr = 0;
    power = 0;
    str_copy = str;
    while (*++str_copy)
        power++;
    str_copy = str;
    while (*str_copy)
    {
        while (base[i]) 
        {
            if (*str_copy == base[i])
                nbr += i * mathpow(getbase, power);
            i++;
        }
        i = 0;
        power--;
        str_copy++;
    }
    return nbr;
}

int ft_atoi_base(char *str, char *base)
{
    int getbase;
    int neg;
    int number;
    char *base_copy;

    base_copy = base;
    getbase = 0;
    neg = 0;
    while (*base_copy++)
        getbase++;
    if (checkbase(base) || getbase < 2 || checkstring(str, base))
        return 0;
    if (str[0] == '-' || str[0] == '+')
    {
        neg = (str[0] == '-') ? 1 : 0;
        str++;
    }
    number = changetodec(str, base, getbase);
    return (neg) ? -1 * number : number;
}