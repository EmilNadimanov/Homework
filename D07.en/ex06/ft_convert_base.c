#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
    char *dest_copy;
    
    dest_copy = dest;
    while(1)
    {
        *dest_copy = *src++;
        if (*dest_copy++ == 0)
            break;
    }
    return dest;
}

int mathpow(int number, int power)
{
	int result;

	result = number;
	while (power > 1)
	{
		result *= number;
		power--;
	}
	return (power == 0) ? 1 : result;
}

int	todec(char *str, char *base, int getbase)
{
	int nbr;
	int i;
	int power;
	int neg;

	i = 0;
	nbr = 0;
	power = -1;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
		neg = (*str++ == '-') ? -1 : 1;
	while (str[power + 1] && str[power + 1] != '.')
		power++;
	while (*str && *str != '.')
	{
		while (base[i])
		{
			if (*str == base[i++])
				nbr += (i - 1) * mathpow(getbase, power);
		}
		i = 0;
		power--;
		++str;
	}
	return nbr * neg;
}

void tobase(long int dec, char *base, char **nbr, int i)
{
	int getbase;

	getbase = 0;
	while (base[getbase])
		getbase++;
	if (dec < 0)
	{
		if (dec >= -2147483648 && dec <= 0)
			nbr[0][0] = '-';
		dec *= -1;
	}
	if (dec / getbase)
	{
		tobase(dec / getbase, base, nbr, i - 1);
		nbr[0][i] = (base[dec % getbase]);
	}
	else
	{
		nbr[0][i] = (base[dec % getbase]);
		return;
	}
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int dec;
	int getbase;
	int memory;
	int dec2;
    char *result;

    strcpy(result, nbr);
	getbase = 0;
	while (base_from[getbase])
		getbase++;
	dec = todec(result, base_from, getbase);
	getbase = 0;
	while (base_to[getbase])
		getbase++;
	dec2 = dec;
	memory = (dec < 0) ? 3 : 2;
	while (dec2 /= getbase)
		memory++;
	result = malloc(memory * sizeof(*result));
	if (!result)
		return NULL;
	tobase(dec, base_to, &result, memory - 2);
	result[memory - 1] = 0;
	return result;
}
