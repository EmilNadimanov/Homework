#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
Create a function ft_count_if which will return the number of elements of the
array that return 1, passed to the function f.
*/
int 		ft_count_if(char **tab, int(*f)(char*))
{
    int 	result;

    result = 0;
    while (*tab)
        if (f(*tab++))
            result++;
    return result;
}

int starts_with_z(char* str)
{
	return str[0] == 'z';
}

int main(int argc, char** argv)
{
	printf("%d", ft_count_if(argv + 1, starts_with_z));
	if (argc < 2)
		return 0;
}
