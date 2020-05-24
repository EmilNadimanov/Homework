#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
		if ((str[counter] >= 48 && str[counter] <= 57) || str[counter] == '-')
		{
			if (str[counter] == '-')
			{
				if_negative = -1;
				counter++;
			}
			else
			{
				number *= 10;
				number = number + ((int)str[counter] - 48);
				counter++;
			}
		}
		else if (if_negative == -1)
			return -number;
		else return number;
	}
	if (if_negative == -1)
		number *= if_negative;
	return number;
}