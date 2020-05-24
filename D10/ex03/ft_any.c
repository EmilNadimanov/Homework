#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
Create a function ft_any which will return 1 if, passed to the function f, at least
one element of the array returns 1. Else, it should return 0.
*/
int 	ft_any(char **tab, int(*f)(char*))
{
	while (*tab)
		if (f(*tab++))
			return 1;
	return 0;
}

int starts_with_z(char* str)
{
	return str[0] == 'z';
}

int main(int argc, char** argv)
{
	printf("%d", ft_any(argv + 1, starts_with_z));
	if (argc < 2)
		return 1;
}