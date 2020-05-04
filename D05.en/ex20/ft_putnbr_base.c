#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

int checkbase(char *base)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (base[i])
    {
        if ((base[i] >= 65 && base[i] <= 90) 
            || (base[i] >= 97 && base[i] <= 122)
            || (base[i] >= 48 && base[i] <= 57))
            i++;
        else
            return 1;
    }
    i = 0;
    while (base[i])
    {
        while (base[j])
        {
            if (base[i] == base [j++])
                return 1;
        }
        j = ++i + 1;
    }
    return 0;
}

void ft_putnbr_base(int nbr, char *base)
{
    int getbase;
    char* base_copy;

    base_copy = base;
    getbase = 0;
    while (*base_copy++)
        getbase++;
    if (checkbase(base) || getbase < 2)
        return;
    if (nbr < 0)
    {
        if (nbr * -1 != nbr)
            ft_putchar('-');
        nbr *= -1;
    }
    if (nbr / getbase)
    {
        ft_putnbr_base(nbr / getbase, base);
        ft_putchar(base[nbr % getbase]);
    }
    else
    {
        ft_putchar(base[nbr % getbase]);
       return;
    }
}
