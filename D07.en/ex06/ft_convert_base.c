#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
Create a function that returns the result of the conversion of
the string nbr from abase base_from to a base base_to. The 
string must have enough allocated memory.

The number represented by nbr must fit inside an int.
*/

int mathpow (int number, int power)
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

int todec(char *str, char *base, int getbase)
{
	int nbr;
	int i;
	int power;
	int neg;

	i = 0;
	nbr = 0;
	power = -1;
	neg = 1;
	if (str[i] == '-' || str[i] == '+' )
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

void tobase(long int dec, char *base, int getbase, char **nbr)
{
	static int i = 0;
	
	if (dec < 0)
	{
		if (dec >= -2147483648 && dec <= 0)
			nbr[0][i++] = '-'; //
		dec *= -1;
	}
	if (dec / getbase)
	{
		tobase(dec / getbase, base, getbase, nbr);
		nbr[0][i++] = (base[dec % getbase]);
	}
	else
	{
		nbr[0][i++] = (base[dec % getbase]);
		return;
	}
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int dec;
	int getbase;
	int memory;
	int dec2;

	getbase = 0;
	while (base_from[getbase])
		getbase++;
	dec = todec(nbr, base_from, getbase);
	getbase = 0;
	while (base_to[getbase])
		getbase++;
	dec2 = dec;
	memory = (dec < 0) ? 3 : 2;
	while (dec2 /= getbase)
		memory++;
	nbr = malloc(memory * sizeof(*nbr));
	if (!nbr)
		return NULL;
	tobase(dec, base_to, getbase, &nbr);
	nbr[memory - 1] = 0;
	return nbr;
}

int main(void)
{
	printf ("Test 1\n");
	printf ("%s\n", ft_convert_base("15", "0123456789", "01"));

	printf ("Test 2\n");
	printf ("%s\n", ft_convert_base("10000", "01", "0123456789"));

	printf ("Test 3\n");
	printf ("%s\n", ft_convert_base("-31", "0123456789", "0123456789abcdef"));

	printf ("Test 4\n");
	printf ("%s\n",n = ft_convert_base("+1f", "0123456789abcdef", "0123456789"));
	
	printf ("Test 5\n");
	printf ("%s\n",n = ft_convert_base("0", "0123456789", "0123456789abcdef"));

	printf ("Test 6\n");
	printf ("%s\n",n = ft_convert_base("0.1234567", "0123456789", "0123456789"));

	printf ("Test 7\n");
	printf ("%s\n",n = ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));

	printf ("Test 8\n");
	printf ("%s\n",n = ft_convert_base("-80000000", "0123456789abcdef", "0123456789"));
}
